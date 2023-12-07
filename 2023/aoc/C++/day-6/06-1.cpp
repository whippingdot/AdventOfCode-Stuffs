#include "C:\Users\sanja\OneDrive\Documents\Coding\GitHubProjects\AdventOfCode-Stuffs\2023\aoc\aoc.h"

void Day6Part1()
{
  std::vector<std::string> input =
      read_file("C:\\Users\\sanja\\OneDrive\\Documents\\Coding\\GitHubProjects\\AdventOfCode-Stuffs\\2023\\aoc\\C++\\day-6\\input.txt");
  std::vector<char> numbers = {'1', '2', '3', '4', '5', '6', '7', '8', '9', '0'};
  std::vector<int> times = std::vector<int>();
  std::vector<int> distances = std::vector<int>();
  std::vector<int> fastest = std::vector<int>();
  std::string stringy = "";
  int answer = 1;
  int maxX = 0;
  int time = 0;
  int distance = 0;
  int fasty = 0;

  for (int i = 10; i < input[0].size(); i++)
  {
    if (std::find(numbers.begin(), numbers.end(), input[0][i]) != numbers.end())
    {
      for (int x = i; std::find(numbers.begin(), numbers.end(), input[0][x]) != numbers.end(); x++)
      {
        stringy += input[0][x];
        maxX = x;
      }
      i = maxX;
      time = std::stoi(stringy);
      times.push_back(time);
      stringy = "";
    }
  }
  for (int i = 10; i < input[1].size(); i++)
  {
    if (std::find(numbers.begin(), numbers.end(), input[1][i]) != numbers.end())
    {
      for (int x = i; std::find(numbers.begin(), numbers.end(), input[1][x]) != numbers.end(); x++)
      {
        stringy += input[1][x];
        maxX = x;
      }
      i = maxX;
      distance = std::stoi(stringy);
      distances.push_back(distance);
      stringy = "";
    }
  }
  for (int i = 0; i < times.size(); i++)
  {
    for (int x = 0; x < (times[i] / 2); x++)
    {
      if (x * (times[i] - x) > distances[i])
      {
        fasty = times[i] - (2 * x) + 1;
        fastest.push_back(fasty);
        break;
      }
    }
  }
  for (int i = 0; i < fastest.size(); i++)
  {
    answer *= fastest[i];
  }

  std::cout << "You get " << answer << " when multiplying the numbers together\n";
}

int main()
{
  Day6Part1();
  return 0;
}