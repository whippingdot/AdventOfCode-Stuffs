#include "C:\Users\sanja\OneDrive\Documents\Coding\GitHubProjects\AdventOfCode-Stuffs\2023\aoc\aoc.h"

long long int gcd(long long int a, long long int b)
{
  if (b == 0)
  {
    return a;
  }
  return gcd(b, a % b);
}

void Day8Part2()
{
  std::vector<std::string> input =
      read_file("C:\\Users\\sanja\\OneDrive\\Documents\\Coding\\GitHubProjects\\AdventOfCode-Stuffs\\2023\\aoc\\C++\\day-8\\input.txt");
  std::vector<std::string> path = std::vector<std::string>();
  std::vector<std::string> special = std::vector<std::string>();
  std::vector<int> counter = std::vector<int>();
  std::vector<int> finishedCounter = std::vector<int>();
  std::string smol = "";
  int rlIndex = 0;
  int index = 0;
  long long int answer = 0;

  std::string rl = input[0];

  for (int i = 2; i < input.size(); i++)
  {
    smol += input[i][0];
    smol += input[i][1];
    smol += input[i][2];
    path.push_back(smol);
    if (input[i][2] == 'A')
    {
      special.push_back(smol);
    }
    smol = "";
  }

  auto it = std::find(path.begin(), path.end(), smol);

  for (int i = 0; i < special.size(); i++)
  {
    counter.push_back(0);
    finishedCounter.push_back(0);
  }

  while (true)
  {
    for (int i = 0; i < special.size(); i++)
    {
      it = std::find(path.begin(), path.end(), special[i]);
      index = it - path.begin();
      index += 2;

      if (rl[rlIndex] == 'R')
      {
        smol = "";
        smol += input[index][12];
        smol += input[index][13];
        smol += input[index][14];
        special[i] = smol;
        counter[i]++;
        if (input[index][14] == 'Z')
        {
          if (finishedCounter[i] == 0)
          {
            finishedCounter[i] = counter[i];
          }
        }
      }
      else
      {
        smol = "";
        smol += input[index][7];
        smol += input[index][8];
        smol += input[index][9];
        special[i] = smol;
        counter[i]++;
        if (input[index][9] == 'Z')
        {
          if (finishedCounter[i] == 0)
          {
            finishedCounter[i] = counter[i];
          }
        }
      }
    }
    rlIndex++;
    if (rlIndex == rl.size())
    {
      rlIndex = 0;
    }
    if (std::find(finishedCounter.begin(), finishedCounter.end(), 0) == finishedCounter.end())
    {
      answer = finishedCounter[0];
      for (int x = 1; x < finishedCounter.size(); x++)
      {
        answer = (answer * finishedCounter[x]) / gcd(answer, finishedCounter[x]);
      }
      break;
    }
  }

  std::cout << "It took " << answer << " steps to get to all As to Zs\n";
}

int main()
{
  Day8Part2();
  return 0;
}