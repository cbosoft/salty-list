#pragma once

#include <string>
#include <ctime>

class Block {
  private:
    std::size_t index;
    std::size_t previous_hash;
    std::size_t proof;
    std::time_t timestamp;
    std::string payload;

  public:
    Block(std::size_t index, 
        std::size_t previous_hash,
        std::size_t proof, 
        std::time_t timestamp, 
        std::string payload);

    std::size_t get_previous_hash();
    void print();
};
