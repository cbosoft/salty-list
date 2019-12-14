#include <sstream>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <random>

#include <sys/stat.h>

#include <nlohmann/json.hpp>

#include "chain.hpp"
#include "block.hpp"




BlockChain::BlockChain(std::string path)
{
  this->path = path;
  this->version = VERSION;
  this->complexity = 1000;
  this->stochastic = false;

  struct stat buffer;
  if (stat (path.c_str(), &buffer) != 0) {
    return;
  }

  std::ifstream istr(this->path);

  nlohmann::json j;
  istr >> j;

  this->version = j["version"];
  this->complexity = j["complexity"];
  this->stochastic = j["stochastic"];
  
  std::size_t index, prev, proof, timestamp;
  std::string payload;
  for (auto block_json : j["blocks"]) {
    index = block_json["index"];
    prev = block_json["previous_hash"];
    proof = block_json["proof"];
    timestamp = block_json["timestamp"];
    payload = block_json["payload"];
    this->add_new_block(index, prev, proof, timestamp, payload);
  }

}





std::size_t BlockChain::get_previous_hash()
{
  if (this->chain.size() == 0)
    return 0;

  //return this->chain.back()->get_previous_hash();
  return this->chain.back()->get_this_hash();
}




bool BlockChain::validate(std::size_t prev, std::size_t cur)
{
  std::stringstream ss;
  ss << prev << cur;
  std::string concat;

  std::size_t hash = std::hash<std::string>{}(concat);
  return hash % 10000 == 0;
}




std::size_t BlockChain::get_proof(std::size_t prev)
{
  std::size_t guess = 0;
  while (not this->validate(prev, guess))
    if (this->stochastic)
      guess = rand();
    else
      guess++;
  return guess;
}



void BlockChain::add_new_block(std::size_t proof, std::size_t prev, std::string payload)
{
  std::size_t index = this->chain.size();
  std::time_t timestamp = std::time(NULL);
  Block *block = new Block(index, prev, proof, timestamp, payload);
  this->chain.push_back(block);
}



void BlockChain::store(std::string payload)
{
  std::size_t prev = this->get_previous_hash();
  std::size_t proof = this->get_proof(prev);
  this->add_new_block(proof, prev, payload);
}



void BlockChain::print()
{
  for (auto block : this->chain) {
    block->print();



void BlockChain::write()
{
  nlohmann::json j;
  j["version"] = this->version;
  j["complexity"] = this->complexity;
  j["stochastic"] = this->stochastic;
  j["blocks"] = nlohmann::json::array();

  for (auto block : this->chain) {
    j["blocks"].push_back(nlohmann::json(
          {
            {"index", block->get_index()},
            {"previous_hash", block->get_previous_hash()},
            {"proof", block->get_proof()},
            {"timestamp", block->get_timestamp()},
            {"payload", block->get_payload()}
          }
          ));
  }

  std::ofstream ostr(this->path, std::ios::trunc);

  ostr << std::setw(2) << j;
}
