#include "C:\Users\sanja\OneDrive\Documents\Coding\GitHubProjects\AdventOfCode-Stuffs\2023\aoc\aoc.h"

void Day1Part2()
{
  std::vector<std::string> input =
      read_file("C:\\Users\\sanja\\OneDrive\\Documents\\Coding\\GitHubProjects\\AdventOfCode-Stuffs\\2023\\aoc\\C++\\day-1\\input.txt");
  bool firstNumber = false;
  bool notherOne = false;
  char tens = 0;
  char ones = 0;
  std::string answerS = "";
  int answer = 0;
  int counter = 0;

  for (std::string &line : input)
  {
    for (int i = 0; i < line.size(); i++)
    {
      switch (line[i])
      {
      case 'o':
        if ((i + 2) < line.size())
        {
          if (line[i + 1] == 'n' && line[i + 2] == 'e')
          {
            if (!firstNumber)
            {
              tens = '1';
              firstNumber = true;
            }
            else
            {
              ones = '1';
              notherOne = true;
            }
          }
        }
        break;
      case 't':
        if ((i + 4) < line.size())
        {
          if (line[i + 1] == 'h' && line[i + 2] == 'r' && line[i + 3] == 'e' && line[i + 4] == 'e')
          {
            if (!firstNumber)
            {
              tens = '3';
              firstNumber = true;
            }
            else
            {
              ones = '3';
              notherOne = true;
            }
          }
        }
        if ((i + 2) < line.size())
        {
          if (line[i + 1] == 'w' && line[i + 2] == 'o')
          {
            if (!firstNumber)
            {
              tens = '2';
              firstNumber = true;
            }
            else
            {
              ones = '2';
              notherOne = true;
            }
          }
        }
        break;
      case 'f':
        if ((i + 3) < line.size())
        {
          if (line[i + 1] == 'o' && line[i + 2] == 'u' && line[i + 3] == 'r')
          {
            if (!firstNumber)
            {
              tens = '4';
              firstNumber = true;
            }
            else
            {
              ones = '4';
              notherOne = true;
            }
          }
          else if (line[i + 1] == 'i' && line[i + 2] == 'v' && line[i + 3] == 'e')
          {
            if (!firstNumber)
            {
              tens = '5';
              firstNumber = true;
            }
            else
            {
              ones = '5';
              notherOne = true;
            }
          }
        }
        break;
      case 's':
        if ((i + 4) < line.size())
        {
          if (line[i + 1] == 'e' && line[i + 2] == 'v' && line[i + 3] == 'e' && line[i + 4] == 'n')
          {
            if (!firstNumber)
            {
              tens = '7';
              firstNumber = true;
            }
            else
            {
              ones = '7';
              notherOne = true;
            }
          }
        }
        if ((i + 2) < line.size())
        {
          if (line[i + 1] == 'i' && line[i + 2] == 'x')
          {
            if (!firstNumber)
            {
              tens = '6';
              firstNumber = true;
            }
            else
            {
              ones = '6';
              notherOne = true;
            }
          }
        }
        break;
      case 'e':
        if ((i + 4) < line.size())
        {
          if (line[i + 1] == 'i' && line[i + 2] == 'g' && line[i + 3] == 'h' && line[i + 4] == 't')
          {
            if (!firstNumber)
            {
              tens = '8';
              firstNumber = true;
            }
            else
            {
              ones = '8';
              notherOne = true;
            }
          }
        }
        break;
      case 'n':
        if ((i + 3) < line.size())
        {
          if (line[i + 1] == 'i' && line[i + 2] == 'n' && line[i + 3] == 'e')
          {
            if (!firstNumber)
            {
              tens = '9';
              firstNumber = true;
            }
            else
            {
              ones = '9';
              notherOne = true;
            }
          }
        }
        break;
      default:
        break;
      }
      if (line[i] == '1' || line[i] == '2' || line[i] == '3' || line[i] == '4' || line[i] == '5' || line[i] == '6' || line[i] == '7' || line[i] == '8' || line[i] == '9')
      {
        if (!firstNumber)
        {
          tens = line[i];
          firstNumber = true;
        }
        else
        {
          ones = line[i];
          notherOne = true;
        }
      }
    }
    if (!notherOne)
    {
      ones = tens;
    }
    answerS += tens;
    answerS += ones;
    counter++;
    answer += std::stoi(answerS);
    answerS = "";
    firstNumber = false;
    notherOne = false;
  }
  std::cout << "The sum of callibration values are: " << answer << std::endl;
}

int main()
{
  Day1Part2();
  return 0;
}