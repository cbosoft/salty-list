#include <iostream>

#include "chain.hpp"


int main(void)
{
  BlockChain chain("path");

  chain.store("hello_world");
  chain.store("hello_world");
  chain.store("hello_world");
  chain.store("hello_world");

}
