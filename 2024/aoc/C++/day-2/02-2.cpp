#include "C:\Users\sanja\OneDrive\Documents\Coding\GitHubProjects\AdventOfCode-Stuffs\2024\aoc\aoc.h"

void Day2Part2()
{
  std::vector<std::string> input = read_file("C:\\Users\\sanja\\OneDrive\\Documents\\Coding\\GitHubProjects\\AdventOfCode-Stuffs\\2024\\aoc\\C++\\day-2\\input.txt");
  int answer = 0;
  std::string numS = "";
  int num = 0;
  int numP = 0;
  bool increase = false;
  bool decrease = false;
  bool firstTime = true;

  for (std::string &line : input)
  {
    for (int i = 0; i < line.size(); i++)
    {
      if (line[i] != ' ')
      {
        numS += line[i];
      }

      if (line[i] == ' ' || i == line.size() - 1)
      {
        if (i == 2)
        numP = num;
        num = std::stoi(numS);
        numS = "";
        if (numP != 0 && !increase && !decrease)
        {
          if (numP < num)
          {
            increase = true;
          }
          else
          {
            decrease = true;
          }
        }
        if (increase)
        {
          if (!(numP < num && num - numP <= 3))
          {
            if (firstTime) {
              num = numP;
              firstTime = false;
              continue;
            }
            increase = false;
            std::cout << line << "\n" << numP << " " << num << std::endl;
            // issue is 24 26 23 ... where 26 should be skipped (check if n3 follows same pattern as n2. If not, check n4 following pattern with n2 and if it does continue normally otherwise skip n2 instead (i++ and firstTime = false). Store the first number till i3 finishes
            break;
          }
        }
        else if (decrease)
        {
          if (!(numP > num && numP - num <= 3))
          {
            if (firstTime) {
              num = numP;
              firstTime = false;
              continue;
            }
            decrease = false;
            std::cout << line << "\n" << numP << " " << num << std::endl;
            break;
          }
        }
      }
    }
    if (decrease || increase)
    {
      answer++;
      increase = false;
      decrease = false;
    }
    numP = 0;
    num = 0;
    firstTime = true;
  }

  std::cout << "The answer is " << answer << std::endl;
}

int main()
{
  Day2Part2();
  return 0;
}