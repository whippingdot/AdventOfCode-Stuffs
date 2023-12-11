#include "C:\Users\sanja\OneDrive\Documents\Coding\GitHubProjects\AdventOfCode-Stuffs\2023\aoc\aoc.h"

void Day9Part1()
{
  std::vector<std::string> input =
      read_file("C:\\Users\\sanja\\OneDrive\\Documents\\Coding\\GitHubProjects\\AdventOfCode-Stuffs\\2023\\aoc\\C++\\day-9\\input.txt");
  std::vector<std::vector<std::vector<int>>> aps = std::vector<std::vector<std::vector<int>>>();
  std::vector<std::vector<int>> diffs = std::vector<std::vector<int>>();
  std::vector<int> singleAP = std::vector<int>();
  std::string stringy = "";
  int x = 0;
  int answer = 0;
  int difference = 0;
  int integer = 0;
  int aInteger = 0;
  int placeInt = 0;
  bool nonZero = false;

  for (int i = 0; i < input.size(); i++)
  {
    for (int j = 0; j < input[i].size(); j++)
    {
      while (std::find(numbers.begin(), numbers.end(), input[i][j]) != numbers.end() || input[i][j] == '-')
      {
        stringy += input[i][j];
        j++;
      }
      integer = std::stoi(stringy);
      stringy = "";
      singleAP.push_back(integer);
    }
    diffs.push_back(singleAP);
    singleAP.clear();
    nonZero = true;
    for (int j = 0; nonZero; j++)
    {
      nonZero = false;
      for (int y = 1; y < diffs[j].size(); y++)
      {
        difference = diffs[j][y] - diffs[j][y - 1];
        if (difference != 0)
        {
          nonZero = true;
        }
        singleAP.push_back(difference);
      }
      diffs.push_back(singleAP);
      singleAP.clear();
    }
    placeInt = diffs.size() - 1;
    diffs[placeInt].push_back(0);
    placeInt--;
    for (int j = placeInt; j >= 0; j--)
    {
      aInteger = diffs[j].size() - 1;
      integer = diffs[j][aInteger] + diffs[j + 1][aInteger];
      diffs[j].push_back(integer);
    }

    aps.push_back(diffs);
    diffs.clear();
  }

  for (int i = 0; i < aps.size(); i++)
  {
    aInteger = aps[i][0].size() - 1;
    answer += aps[i][0][aInteger];
  }

  std::cout << std::format("Adding the new history values, you get {}", answer) << std::endl;
}

int main()
{
  Day9Part1();
  return 0;
}