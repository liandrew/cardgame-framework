#ifndef UTILITY_H
#define UTILITY_H

#include <string>
#include <vector>

class Utility {
public:
  static std::string toString(int d);
  static std::string toString(float d);

  // http://stackoverflow.com/questions/236129/split-a-string-in-c
  static std::vector<std::string> split(std::string s, char delim);
};

#endif