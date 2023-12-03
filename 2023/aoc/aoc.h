#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <map>
#include <chrono>
#include <fstream>
#include <algorithm>
#include <typeinfo>
#include <ctype.h>

std::vector<std::string> read_file(std::string name)
{
  std::vector<std::string> lines = std::vector<std::string>();
  std::string line;

  std::fstream file(name);

  while (getline(file, line))
  {
    lines.push_back(line);
  }

  return lines;
}