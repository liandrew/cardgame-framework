#include "../include/Utility.h"

#include <sstream>

std::string Utility::toString(int d) {
  std::stringstream ss;
  ss << d;
  return ss.str();
}

std::string Utility::toString(float d) {
  std::stringstream ss;
  ss << d;
  return ss.str();
}

std::vector<std::string> Utility::split(std::string s, char delim) {
  std::vector<std::string> elems;
  std::stringstream ss(s);
  std::string item;
  while (std::getline(ss, item, delim)) {
    elems.push_back(item);
  }
  return elems;
}