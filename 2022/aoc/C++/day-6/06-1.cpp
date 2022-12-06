#include "..\aoc.h"

void Day6Part1()
{
  std::vector<std::string> input = read_file("C:\\Users\\sanja\\OneDrive\\Documents\\Coding\\GitHubProjects\\AdventOfCode-Stuffs\\2022\\aoc\\C++\\day-6\\input.txt");
  int answer = 4;

  char var1 = ' ';
  char var2 = ' ';
  char var3 = ' ';

  bool var1Defined = false;
  bool var2Defined = false;
  bool var3Defined = false;

  for (std::string l : input)
  {
    for (char c : l)
    {
      if (!var1Defined)
      {
        var1Defined = true;
        var1 = c;
      }
      else if (!var2Defined)
      {
        var2Defined = true;
        var2 = c;
      }
      else if (!var3Defined)
      {
        var3Defined = true;
        var3 = c;
      }
      else
      {
        if (c != var1 && c != var2 && c != var3 && var1 != var2 && var1 != var3 && var2 != var3)
        {
          break;
        }
        else
        {
          // std::cout << "Var 3: " << var3 << std::endl;
          var3 = var2;
          // std::cout << "Var 3: " << var3 << std::endl;
          // std::cout << "Var 2: " << var2 << std::endl;
          var2 = var1;
          // std::cout << "Var 2: " << var2 << std::endl;
          // std::cout << "Var 1: " << var1 << std::endl;
          var1 = c;
          // std::cout << "Var 1: " << var1 << std::endl;
        }
        answer++;
      }
    }
  }

  std::cout << "The answer is " << answer << std::endl;
}

int main()
{
  Day6Part1();
  return 0;
}