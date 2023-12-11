#include "C:\Users\sanja\OneDrive\Documents\Coding\GitHubProjects\AdventOfCode-Stuffs\2023\aoc\aoc.h"

void Day8Part1()
{
  std::vector<std::string> input =
      read_file("C:\\Users\\sanja\\OneDrive\\Documents\\Coding\\GitHubProjects\\AdventOfCode-Stuffs\\2023\\aoc\\C++\\day-8\\input.txt");
  std::vector<std::string> path = std::vector<std::string>();
  std::string smol = "";
  int rlIndex = 0;
  int index = 0;
  int answer = 0;
  bool zz = false;

  std::string rl = input[0];

  for (int i = 2; i < input.size(); i++)
  {
    smol += input[i][0];
    smol += input[i][1];
    smol += input[i][2];
    path.push_back(smol);
    smol = "";
  }

  smol = "AAA";
  auto it = std::find(path.begin(), path.end(), smol);
  index = it - path.begin();

  while (!zz)
  {
    it = std::find(path.begin(), path.end(), smol);
    index = it - path.begin();
    index += 2;

    if (rl[rlIndex] == 'R')
    {
      smol = "";
      smol += input[index][12];
      smol += input[index][13];
      smol += input[index][14];
      answer++;
    }
    else
    {
      smol = "";
      smol += input[index][7];
      smol += input[index][8];
      smol += input[index][9];
      answer++;
    }
    rlIndex++;
    if (rlIndex == rl.size())
    {
      rlIndex = 0;
    }
    if (smol == "ZZZ")
    {
      zz = true;
    }
  }

  std::cout << "It took " << answer << " steps to get to ZZZ\n";
}

int main()
{
  Day8Part1();
  return 0;
}