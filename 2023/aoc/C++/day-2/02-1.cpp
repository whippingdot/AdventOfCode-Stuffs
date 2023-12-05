#include "C:\Users\sanja\OneDrive\Documents\Coding\GitHubProjects\AdventOfCode-Stuffs\2023\aoc\aoc.h"

const int R_MAX = 12;
const int G_MAX = 13;
const int B_MAX = 14;

void Day2Part1()
{
  std::vector<std::string> input = read_file("C:\\Users\\sanja\\OneDrive\\Documents\\Coding\\GitHubProjects\\AdventOfCode-Stuffs\\2023\\aoc\\C++\\day-2\\input.txt");
  int answer = 0;
  bool started = false;
  bool unbroken = true;
  char rgb = ' ';
  std::string num = "";
  int numi = 0;
  int nume = 0;
  int max = 0;

  for (std::string &line : input)
  {
    for (int i = 0; i < line.size(); i++)
    {
      if (line[i] == '1' || line[i] == '2' || line[i] == '3' || line[i] == '4' || line[i] == '5' || line[i] == '6' || line[i] == '7' || line[i] == '8' || line[i] == '9')
      {
        if (!started)
        {
          for (int x = i; line[x] != ':'; x++)
          {
            num += line[x];
            max = x;
          }
          numi = std::stoi(num);
          num = "";
          i = max;
        }
        else
        {
          if (line[i + 1] == ' ')
          {
            continue;
          }
          else
          {
            for (int z = i; line[z] != ' '; z++)
            {
              num += line[z];
              max = z;
            }
            nume = std::stoi(num);
            num = "";
            max += 2;
            if (line[max] == 'r')
            {
              if (nume > R_MAX)
              {
                unbroken = false;
                break;
              }
            }
            else if (line[max] == 'g')
            {
              if (nume > G_MAX)
              {
                unbroken = false;
                break;
              }
            }
            else
            {
              if (nume > B_MAX)
              {
                unbroken = false;
                break;
              }
            }
          }
        }
      }
      if (line[i] == ':')
      {
        started = true;
      }
    }
    if (unbroken)
    {
      answer += numi;
    }
    else
    {
      unbroken = true;
    }
    started = false;
  }
  std::cout << "The answer is " << answer << std::endl;
}

int main()
{
  Day2Part1();
  return 0;
}