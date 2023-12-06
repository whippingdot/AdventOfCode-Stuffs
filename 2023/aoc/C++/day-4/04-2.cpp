#include "C:\Users\sanja\OneDrive\Documents\Coding\GitHubProjects\AdventOfCode-Stuffs\2023\aoc\aoc.h"

void Day4Part2()
{
  std::vector<std::string> input =
      read_file("C:\\Users\\sanja\\OneDrive\\Documents\\Coding\\GitHubProjects\\AdventOfCode-Stuffs\\2023\\aoc\\C++\\day-4\\input.txt");
  std::vector<std::string> winners = std::vector<std::string>();
  std::vector<int> scratchCards = std::vector<int>();
  std::string sNum = "";
  int answer = 0;
  int winNum = 0;
  int lineNum = 0;

  for (int i = 0; i < input.size(); i++)
  {
    scratchCards.push_back(1);
  }

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
    for (int i = 1; i <= winNum; i++)
    {
      scratchCards[lineNum + i] += scratchCards[lineNum];
    }
    winners.clear();
    winNum = 0;
    lineNum++;
  }

  for (int i = 0; i < scratchCards.size(); i++)
  {
    answer += scratchCards[i];
  }

  std::cout << "We end up with " << answer << " scratchcards\n";
}

int main()
{
  Day4Part2();
  return 0;
}