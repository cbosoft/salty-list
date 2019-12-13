#include <functional>

#include "salty_list.hpp"


SaltyList::SaltyList(std::string path)
{
  this->path = path;

  // TODO check if file is empty
  // if not: load blocks
}

Block::Block(size_t index, size_t previous_hash, time_t timestamp, std::string payload)
{
  this->index = index;
  this->previous_hash = previous_hash;
  this->timestamp = timestamp;
  this->payload = payload;
}
