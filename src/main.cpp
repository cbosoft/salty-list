#include <iostream>

#include "salty_list.hpp"


int main(void)
{
  SaltyList sl("path");
  std::cout << sl.get_latest_hash() << std::endl;
}
