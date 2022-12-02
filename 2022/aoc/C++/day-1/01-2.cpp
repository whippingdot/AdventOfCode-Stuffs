#include "..\aoc.h"

void Day1Part2()
{
  std::vector<std::string> input = read_file("C:\\Users\\sanja\\OneDrive\\Documents\\Coding\\GitHubProjects\\AdventOfCode-Stuffs\\2022\\aoc\\C++\\day-1\\input.txt");
  int answer = 0;
  int value = 0;
  int valuePlus = 0;
  int leastValue = 0;

  int topThree[3] = {0, 0, 0};

  bool changed = false;
  
  for (std::string &line : input) {
    if (line == "") {
      for (int i = 1; i < 4; i++) {
        if (valuePlus > topThree[i-1]) {
          if (topThree[i-1] < topThree[leastValue] || topThree[i-1] == 0) {
            leastValue = i-1;
            changed = true;
          }
        }
      }
      if (changed != false) {
        topThree[leastValue] = valuePlus;
      }
      valuePlus = 0;
      leastValue = 0;
      changed = false;
    }
    else {
      value = std::stoi(line);
      valuePlus += value;
      value = 0;
    }
  }

  for (int i = 0; i < 3; i++) {
    answer += topThree[i];
  }
  std::cout << "The highest consecutive numbers added up together is " << answer << std::endl;
}

int main()
{
  Day1Part2();
  return 0;
}