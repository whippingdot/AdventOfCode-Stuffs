#include "C:\Users\sanja\OneDrive\Documents\Coding\GitHubProjects\AdventOfCode-Stuffs\2023\aoc\aoc.h"

void Day2Part2()
{
  std::vector<std::string> input = read_file("C:\\Users\\sanja\\OneDrive\\Documents\\Coding\\GitHubProjects\\AdventOfCode-Stuffs\\2023\\aoc\\C++\\day-2\\input.txt");
  int answer = 0;
  bool started = false;
  char rgb = ' ';
  std::string num = "";
  int nume = 0;
  int max = 0;
  int rmin = 0;
  int gmin = 0;
  int bmin = 0;

  for (std::string &line : input)
  {
    for (int i = 0; i < line.size(); i++)
    {
      if (line[i] == '1' || line[i] == '2' || line[i] == '3' || line[i] == '4' || line[i] == '5' || line[i] == '6' || line[i] == '7' || line[i] == '8' || line[i] == '9')
      {
        if (started)
        {
          for (int z = i; line[z] != ' '; z++)
          {
            num += line[z];
            max = z;
          }
          i = max;
          nume = std::stoi(num);
          num = "";
          max += 2;
          if (line[max] == 'r')
          {
            if (nume > rmin)
            {
              rmin = nume;
            }
          }
          else if (line[max] == 'g')
          {
            if (nume > gmin)
            {
              gmin = nume;
            }
          }
          else
          {
            if (nume > bmin)
            {
              bmin = nume;
            }
          }
        }
      }
      else if (line[i] == ':')
      {
        started = true;
      }
    }
    answer += (rmin * gmin * bmin);
    rmin = 0;
    gmin = 0;
    bmin = 0;

    started = false;
  }
  std::cout << "The answer is " << answer << std::endl;
}

int main()
{
  Day2Part2();
  return 0;
}