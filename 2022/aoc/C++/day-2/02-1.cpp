#include "..\aoc.h"

void Day2Part1() {
  std::vector<std::string> input =
      read_file("C:"
                "\\Users\\sanja\\OneDrive\\Documents\\Coding\\GitHubProjects\\A"
                "dventOfCode-Stuffs\\2022\\aoc\\C++\\day-2\\input.txt");
  int answer = 0;
  int lineValue = 0;

  char enemy = ' ';

  for (std::string l : input) {
    for (char c : l) {
      if (c == 'X') {
        lineValue += 1;
      } else if (c == 'Y') {
        lineValue += 2;
      } else if (c == 'Z') {
        lineValue += 3;
      }

      if (c == 'A' || c == 'B' || c == 'C') {
        enemy = c;
        continue;
      }

      if ((enemy == 'A' && c == 'X') || (enemy == 'B' && c == 'Y') ||
          (enemy == 'C' && c == 'Z')) {
        lineValue += 3;
      } else if ((enemy == 'A' && c == 'Y') || (enemy == 'B' && c == 'Z') ||
                 (enemy == 'C' && c == 'X')) {
        lineValue += 6;
      }
      // std::cout << "Enemy and C: " << enemy << " and " << c << "\nLineValue =
      // " << lineValue << std::endl;
    }
    answer += lineValue;
    lineValue = 0;
    enemy = ' ';
  }

  std::cout << "The answer is " << answer << std::endl;
}

int main() {
  Day2Part1();
  return 0;
}