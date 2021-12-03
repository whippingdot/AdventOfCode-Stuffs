#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <map>
#include <chrono>

using std::cout;
using std::cin;
using std::endl;
using std::getline;
using std::vector;
using std::map;
using std::stoi;
using std::string;
using std::fstream;

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