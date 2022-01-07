#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <map>
#include <chrono>
#include <fstream>
#include <algorithm>
#include <typeinfo>

using std::cin;
using std::cout;
using std::endl;
using std::find;
using std::fstream;
using std::getline;
using std::map;
using std::stoi;
using std::string;
using std::vector;

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