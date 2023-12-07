#include "C:\Users\sanja\OneDrive\Documents\Coding\GitHubProjects\AdventOfCode-Stuffs\2023\aoc\aoc.h"

void Day6Part2()
{
  std::vector<std::string> input =
      read_file("C:\\Users\\sanja\\OneDrive\\Documents\\Coding\\GitHubProjects\\AdventOfCode-Stuffs\\2023\\aoc\\C++\\day-6\\input.txt");
  std::vector<char> numbers = {'1', '2', '3', '4', '5', '6', '7', '8', '9', '0'};
  std::string stringy = "";
  long long int answer = 0;
  long long int time = 0;
  long long int distance = 0;
  int base = 10;
  char *endptr = NULL;

  for (int i = 10; i < input[0].size(); i++)
  {
    if (std::find(numbers.begin(), numbers.end(), input[0][i]) != numbers.end())
    {
      stringy += input[0][i];
    }
  }
  // New function I learnt to convert a string to long long int. To convert to long int you need strtol
  time = std::strtoll(stringy.c_str(), &endptr, base);
  stringy = "";

  for (int i = 10; i < input[1].size(); i++)
  {
    if (std::find(numbers.begin(), numbers.end(), input[1][i]) != numbers.end())
    {
      stringy += input[1][i];
    }
  }

  distance = std::strtoll(stringy.c_str(), &endptr, base);
  stringy = "";

  for (int x = 0; x < (time / 2); x++)
  {
    if (x * (time - x) > distance)
    {
      answer = time - (2 * x) + 1;
      break;
    }
  }

  std::cout << "You can beat the longer race in " << answer << " ways\n";
}

int main()
{
  Day6Part2();
  return 0;
}