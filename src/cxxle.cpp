#include "cxxle.h"
#include <iostream>

#include "cxxle_var.hpp"

cxxle_api *
cxxle(const char *path)
{
  cxxle_api *api = (cxxle_api *)malloc(sizeof(cxxle_api));
  api->message = message;
  return api;
}