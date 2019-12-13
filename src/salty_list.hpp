#include <string>
#include <list>
#include <ctime>

// https://hackernoon.com/learn-blockchains-by-building-one-117428612f46

class Block {
  private:
    std::size_t index;
    std::size_t previous_hash;
    std::time_t timestamp;
    std::string payload;
    std::size_t proof_of_work;
  public:
    Block(size_t index, size_t previous_hash, time_t timestamp, std::string payload);

    std::size_t get_previous_hash() {return this->previous_hash;}
};

class SaltyList {
  private:
    std::list<Block *> chain;

    std::string path;
  public:
    SaltyList(std::string path);

    std::size_t get_previous_hash() {return (*this->chain.end())->get_previous_hash();}
    void new_block(std::size_t proof, std::size_t previous_hash);
};
