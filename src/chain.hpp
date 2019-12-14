#pragma once

#include <list>
#include <string>
#include <functional>

#include "version.hpp"
#include "block.hpp"

class BlockChain {

  private:
    std::list<Block *> chain;
    std::string path;

    bool stochastic;
    std::size_t version;
  public:
    BlockChain(std::string path);

    std::size_t get_previous_hash();
    std::size_t get_proof(std::size_t previous);
    bool validate(std::size_t prev, std::size_t cur);
    void add_new_block(std::size_t index, std::size_t prev, std::size_t proof, std::time_t timestamp, std::string payload);
    void store(std::string payload);

    void save_to_file();
    void print();
    void write();

};
