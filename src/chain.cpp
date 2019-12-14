#include <sstream>
#include "chain.hpp"
#include "block.hpp"




BlockChain::BlockChain(std::string path)
{
  this->path = path;

  // TODO check if file is empty
  // if not: load blocks
}





std::size_t BlockChain::get_previous_hash()
{
  if (this->chain.size() == 0)
    return 0;

  return (*this->chain.end())->get_previous_hash();
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
  while (this->validate(prev, guess)) guess++;
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
  }
}
