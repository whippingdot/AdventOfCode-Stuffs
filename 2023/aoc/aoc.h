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
#include <format>

std::vector<char> numbers = { '1', '2', '3', '4', '5', '6', '7', '8', '9', '0' };

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