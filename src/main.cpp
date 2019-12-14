#include <iostream>

#include <string.h>

#include "chain.hpp"


int main(int argc, const char** argv)
{
  std::string path, store;

  // TODO better error checking/input validation
  for (int i = 1; i < argc; i++) {

    if ((strcmp(argv[i], "-f") == 0) || (strcmp(argv[i], "--file") == 0))
      path = argv[++i];
    else if ((strcmp(argv[i], "-s") == 0) || (strcmp(argv[i], "--store") == 0))
      store = argv[++i];
    else
      std::cerr 
        << "unknown argument: \"" << argv[i] << "\"" << std::endl;
  }

  if (path.size() == 0) {
    std::cerr << "missing argument: -f|--file -> the path to the blockchain file" << std::endl;
    exit(1);
  }

  if (store.size() == 0) {
    std::cerr << "missing argument: -s|--store -> the string blob to store in the chain" << std::endl;
    exit(1);
  }

  BlockChain chain(path);
  chain.store(store);
  chain.write();
}
