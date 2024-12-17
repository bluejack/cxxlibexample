#include "cxxle_var.hpp"

#include <iostream>

void message(const char *path)
{
  std::cout << "Hello from the sub library! (" << path << ")" << std::endl;
}
