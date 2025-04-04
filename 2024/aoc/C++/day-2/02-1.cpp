#include "C:\Users\sanja\OneDrive\Documents\Coding\GitHubProjects\AdventOfCode-Stuffs\2024\aoc\aoc.h"

void Day2Part1()
{
  std::vector<std::string> input = read_file("C:\\Users\\sanja\\OneDrive\\Documents\\Coding\\GitHubProjects\\AdventOfCode-Stuffs\\2024\\aoc\\C++\\day-2\\input.txt");
  int answer = 0;
  std::string numS = "";
  int num = 0;
  int numP = 0;
  bool increase = false;
  bool decrease = false;

  for (std::string& line : input) {
    for (int i = 0; i < line.size(); i++) {
      if (line[i] != ' ') {
        numS += line[i];
        std::cout << numS << std::endl;
      }
      
      if (line[i] == ' ' || i == line.size()-1) {
        numP = num;
        num = std::stoi(numS);
        numS = "";
        if (numP != 0 && !increase && !decrease) {
          if (numP < num) {
            increase = true;
          }
          else {
            decrease = true;
          }
        } 
        if (increase) {
          if (!(numP < num && num - numP <= 3)) {
            increase = false;
            break;
          }
        }
        else if (decrease) {
          if (!(numP > num && numP - num <= 3)) {
            decrease = false;
            break;
          }
        }
      }
    }
    if (decrease || increase) {
      answer++;
      increase = false;
      decrease = false;
    }
    numP = 0;
    num = 0;

  }

  std::cout << "The answer is " << answer << std::endl;
}

int main()
{
  Day2Part1();
  return 0;
}