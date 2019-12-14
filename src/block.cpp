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


std::size_t Block::get_previous_hash()
{
  return this->previous_hash;
}


void Block::print()
std::size_t Block::get_index() const { return this->index; }
std::size_t Block::get_previous_hash() const { return this->previous_hash; }
std::size_t Block::get_proof() const { return this->proof; }
std::size_t Block::get_timestamp() const { return this->timestamp; }
std::string Block::get_payload() const { return this->payload; }
{
  std::cout 
    << "{" << std::endl
    << "block number: " << this->index << std::endl
    << "    prev:      " << this->previous_hash << std::endl
    << "    proof:     " << this->previous_hash << std::endl
    << "    timestamp: " << this->previous_hash << std::endl
    << "    payload:   " << this->previous_hash << std::endl
    << "}" << std::endl
    ;
}
