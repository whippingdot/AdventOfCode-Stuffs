#include <stdlib.h>
#include "aoc.h"

std::string Read_Raw(std::string name)
{
  std::ifstream file(name);

  std::string out = "";

  // While the file has data to read
  while (file.good())
  {
    out += file.get();
  }

  return out.substr(0, out.length() - 1); // Remove EOF character
}

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

int main()
{
  auto start = std::chrono::steady_clock::now();

  std::cout << "\n\nDay 1: \n\n";
  Day1Part1();

  auto end = std::chrono::steady_clock::now();

  std::cout << "Time taken to complete all puzzles: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << "ms\n";

  return 0;
}