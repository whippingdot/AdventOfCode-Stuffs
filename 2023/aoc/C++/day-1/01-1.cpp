#include "C:\Users\sanja\OneDrive\Documents\Coding\GitHubProjects\AdventOfCode-Stuffs\2023\aoc\aoc.h"

void Day1Part1()
{
  std::vector<std::string> input =
      read_file("C:\\Users\\sanja\\OneDrive\\Documents\\Coding\\GitHubProjects\\AdventOfCode-Stuffs\\2023\\aoc\\C++\\day-1\\input.txt");
  bool firstNumber = false;
  bool notherOne = false;
  char tens = 0;
  char ones = 0;
  std::string answerS = "";
  int answer = 0;

  for (std::string &line : input)
  {
    for (char &c : line)
    {
      if (c == '1' || c == '2' || c == '3' || c == '4' || c == '5' || c == '6' || c == '7' || c == '8' || c == '9')
      {
        if (!firstNumber)
        {
          tens = c;
          firstNumber = true;
        }
        else
        {
          ones = c;
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
    answer += std::stoi(answerS);
    answerS = "";
    firstNumber = false;
    notherOne = false;
  }
  std::cout << "The sum of callibration values are: " << answer << std::endl;
}

int main()
{
  Day1Part1();
  return 0;
}