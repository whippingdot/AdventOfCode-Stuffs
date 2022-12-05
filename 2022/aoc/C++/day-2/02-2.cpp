#include "..\aoc.h"

void Day2Part2()
{
  std::vector<std::string> input = read_file("C:\\Users\\sanja\\OneDrive\\Documents\\Coding\\GitHubProjects\\AdventOfCode-Stuffs\\2022\\aoc\\C++\\day-2\\input.txt");
  int answer = 0;
  int lineValue = 0;

  char enemy = ' ';

  for (std::string l : input)
  {
    for (char c : l)
    {
      if (c == 'Y')
      {
        lineValue += 3;
      }
      else if (c == 'Z')
      {
        lineValue += 6;
      }

      if (c == 'A' || c == 'B' || c == 'C')
      {
        enemy = c;
        continue;
      }

      if ((enemy == 'A' && c == 'Y') || (enemy == 'B' && c == 'X') || (enemy == 'C' && c == 'Z'))
      {
        lineValue += 1;
      }
      else if ((enemy == 'A' && c == 'Z') || (enemy == 'B' && c == 'Y') || (enemy == 'C' && c == 'X'))
      {
        lineValue += 2;
      }
      else if ((enemy == 'A' && c == 'X') || (enemy == 'B' && c == 'Z') || (enemy == 'C' && c == 'Y'))
      {
        lineValue += 3;
      }
    }
    answer += lineValue;
    lineValue = 0;
    enemy = ' ';
  }

  std::cout << "The answer is " << answer << std::endl;
}

int main()
{
  Day2Part2();
  return 0;
}