#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <map>
#include <chrono>

#define cout std::cout
#define cin std::cin
#define endl std::endl
#define getline std::getline
#define vector std::vector
#define map std::map
#define stoi std::stoi
typedef std::string string;
typedef std::fstream fstream;

vector<string> read_file(string name)
{
  vector<string> lines = vector<string>();
  string line;

  fstream file(name);

  while (getline(file, line))
  {
    lines.push_back(line);
  }

  return lines;
}

// string Read_Raw(string name);
// vector<string> read_file(string name);

// void Day1Part1();