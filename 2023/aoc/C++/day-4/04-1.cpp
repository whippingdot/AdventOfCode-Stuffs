#include "C:\Users\sanja\OneDrive\Documents\Coding\GitHubProjects\AdventOfCode-Stuffs\2023\aoc\aoc.h"

void Day1Part1()
{
  std::vector<std::string> input =
      read_file("C:\\Users\\sanja\\OneDrive\\Documents\\Coding\\GitHubProjects\\AdventOfCode-Stuffs\\2023\\aoc\\C++\\day-4\\input.txt");
  std::vector<std::string> winners = std::vector<std::string>();
  std::string sNum = "";
  int answer = 0;
  int winNum = 0;

  for (std::string &line : input)
  {
    for (int i = 10; i < 38; i += 3)
    {
      sNum += line[i];
      sNum += line[i + 1];
      winners.push_back(sNum);
      sNum = "";
    }
    for (int i = 42; i < line.size(); i += 3)
    {
      sNum += line[i];
      sNum += line[i + 1];
      if (std::find(winners.begin(), winners.end(), sNum) != winners.end())
      {
        winNum++;
      }
      sNum = "";
    }
    if (winNum > 0)
    {
      answer += pow(2, (winNum - 1));
    }
    winners.clear();
    winNum = 0;
  }

  std::cout << "They are worth " << answer << " points\n";
}

int main()
{
  Day1Part1();
  return 0;
}