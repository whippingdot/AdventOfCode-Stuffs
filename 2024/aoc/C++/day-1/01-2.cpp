#include "C:\Users\sanja\OneDrive\Documents\Coding\GitHubProjects\AdventOfCode-Stuffs\2024\aoc\aoc.h"
void Day1Part2()
{
  std::vector<std::string> input = read_file("C:\\Users\\sanja\\OneDrive\\Documents\\Coding\\GitHubProjects\\AdventOfCode-Stuffs\\2024\\aoc\\C++\\day-1\\input.txt");
  int answer = 0;
  std::vector<int> line1 = std::vector<int>();
  std::vector<int> line2 = std::vector<int>();
  std::string numS = "";
  int num = 0;

  for (std::string &line : input)
  {
    numS += line[0];
    numS += line[1];
    numS += line[2];
    numS += line[3];
    numS += line[4];
    num = std::stoi(numS);
    line1.push_back(num);
    numS = "";
    numS += line[8];
    numS += line[9];
    numS += line[10];
    numS += line[11];
    numS += line[12];
    num = std::stoi(numS);
    line2.push_back(num);
    numS = "";
  }

  for (int i = 0; i < line1.size(); i++)
  {
    num = 0;
    for (int j = 0; j < line2.size(); j++)
    {
      if (line1[i] == line2[j])
      {
        num++;
      }
    }
    answer += num * line1[i];
  }

  std::cout << "The answer is " << answer << std::endl;
}

int main()
{
  Day1Part2();
  return 0;
}