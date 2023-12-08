#include "C:\Users\sanja\OneDrive\Documents\Coding\GitHubProjects\AdventOfCode-Stuffs\2023\aoc\aoc.h"

void transformer(std::vector<long long int> &seedStart, std::vector<int> &indexes, long long int source, long long int range, long long int destination)
{
  std::vector<long long int>::iterator it;
  long long int diff = destination - source;
  for (int a = 0; a < seedStart.size(); a++)
  {
    if (source <= seedStart[a] && seedStart[a] < (source + range) && (std::find(indexes.begin(), indexes.end(), a) == indexes.end()))
    {
      indexes.push_back(a);
      seedStart[a] += diff;
    }
  }
}

void Day5Part1()
{
  std::vector<std::string> input =
      read_file("C:\\Users\\sanja\\OneDrive\\Documents\\Coding\\GitHubProjects\\AdventOfCode-Stuffs\\2023\\aoc\\C++\\day-5\\input.txt");
  std::vector<long long int> transformation = std::vector<long long int>();
  std::vector<int> fIndexes = std::vector<int>();
  std::string sNum = "";
  long long int num = 0;
  long long int ssource = 0;
  long long int destin = 0;
  long long int rrange = 0;
  int answer = 0;
  int fmax = 0;
  bool sourceDone = false;
  char *endptr = NULL;

  for (int i = 7; i < input[0].size(); i++)
  {
    if (std::find(numbers.begin(), numbers.end(), input[0][i]) != numbers.end())
    {
      for (int x = i; std::find(numbers.begin(), numbers.end(), input[0][x]) != numbers.end(); x++)
      {
        sNum += input[0][x];
        i = x;
      }
      num = std::strtoll(sNum.c_str(), &endptr, 10);
      transformation.push_back(num);
      sNum = "";
    }
  }

  for (int i = 3; i < input.size(); i++)
  {
    if (std::find(numbers.begin(), numbers.end(), input[i][0]) != numbers.end())
    {
      for (int x = 0; std::find(numbers.begin(), numbers.end(), input[i][x]) != numbers.end(); x++)
      {
        sNum += input[i][x];
        fmax = x;
      }
      destin = std::strtoll(sNum.c_str(), &endptr, 10);
      sNum = "";
      for (int x = fmax + 1; x < input[i].size(); x++)
      {
        if (std::find(numbers.begin(), numbers.end(), input[i][x]) != numbers.end())
        {
          for (int y = x; std::find(numbers.begin(), numbers.end(), input[i][y]) != numbers.end(); y++)
          {
            sNum += input[i][y];
            fmax = y;
          }
          if (!sourceDone)
          {
            ssource = std::strtoll(sNum.c_str(), &endptr, 10);
            sourceDone = true;
          }
          else
          {
            rrange = std::strtoll(sNum.c_str(), &endptr, 10);
          }
          sNum = "";
          x = fmax;
        }
      }
      sourceDone = false;
      transformer(transformation, fIndexes, ssource, rrange, destin);
    }
    else
    {
      fIndexes.clear();
    }
  }

  for (long long int i : transformation)
  {
    if (i == transformation[0] || i < answer)
    {
      answer = i;
    }
  }

  std::cout << std::format("Lowest location value is {}", answer) << std::endl;
}

int main()
{
  Day5Part1();
  return 0;
}