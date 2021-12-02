#include <stdlib.h>
#include "aoc/aoc.h"

string Read_Raw(string name)
{
  std::ifstream file(name);

  string out = "";

  // While the file has data to read
  while (file.good())
  {
    out += file.get();
  }

  return out.substr(0, out.length() - 1); // Remove EOF character
}

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

int main()
{
  auto start = std::chrono::steady_clock::now();

  cout << "\n\nDay 1: \n\n";
  Day1Part1();

  auto end = std::chrono::steady_clock::now();

  cout << "Time taken to complete all puzzles: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << "ms\n";

  return 0;
}