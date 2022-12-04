#include "..\aoc.h"

void Day1Part1()
{
  std::vector<std::string> input = read_file("C:\\Users\\sanja\\OneDrive\\Documents\\Coding\\GitHubProjects\\AdventOfCode-Stuffs\\2022\\aoc\\C++\\day-1\\input.txt");
  int answer = 0;
  int value = 0;
  int valuePlus = 0;

  for (std::string &line : input)
  {
    if (line == "")
    {
      // std::cout << "Ey baby\n";
      if (valuePlus > answer)
      {
        // std::cout << "Ey Royce " << valuePlus << std::endl;
        answer = valuePlus;
      }
      valuePlus = 0;
    }
    else
    {
      value = std::stoi(line);
      // std::cout << "Ey EEE " << value << std::endl;
      valuePlus += value;
      value = 0;
    }
  }

  std::cout << "The highest consecutive numbers added up together is " << answer << std::endl;
}

int main()
{
  Day1Part1();
  return 0;
}