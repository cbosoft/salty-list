#include <iostream>

#include "block.hpp"

Block::Block(std::size_t index, 
    std::size_t previous_hash, 
    std::size_t proof,
    std::time_t timestamp, 
    std::string payload)
{
  this->index = index;
  this->previous_hash = previous_hash;
  this->proof = proof;
  this->timestamp = timestamp;
  this->payload = payload;
}




std::size_t Block::get_index() const { return this->index; }
std::size_t Block::get_previous_hash() const { return this->previous_hash; }
std::size_t Block::get_proof() const { return this->proof; }
std::size_t Block::get_timestamp() const { return this->timestamp; }
std::string Block::get_payload() const { return this->payload; }


void Block::print() const
{
  std::cout 
    << "{" << std::endl
    << "block number: " << this->index << std::endl
    << "    prev:      " << this->previous_hash << std::endl
    << "    proof:     " << this->proof << std::endl
    << "    timestamp: " << this->timestamp << std::endl
    << "    payload:   " << this->payload << std::endl
    << "}" << std::endl
    ;
}


std::size_t Block::get_this_hash() const 
{
  std::size_t hash_payload = std::hash<std::string>{}(this->payload);
  std::size_t hash_proof = std::hash<std::size_t>{}(this->proof);
  std::size_t hash_timestamp = std::hash<std::size_t>{}(this->timestamp);
  return ((hash_payload ^ (hash_proof << 1)) ^ (this->previous_hash << 1)) ^ (hash_timestamp << 1);
};
