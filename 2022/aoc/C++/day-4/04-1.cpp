#include "..\aoc.h"

void Day4Part1()
{
  std::vector<std::string> input = read_file("C:\\Users\\sanja\\OneDrive\\Documents\\Coding\\GitHubProjects\\AdventOfCode-Stuffs\\2022\\aoc\\C++\\day-4\\input.txt");
  int answer = 0;
  int var = 0;
  int curVal = 0;

  std::string currentVal = "";

  bool commaPassed = false;

  int firstTwo[2] = {0, 0};
  int lastTwo[2] = {0, 0};

  for (std::string l : input) {
    if (var != 0) {
      curVal = std::stoi(currentVal);
      lastTwo[1] = curVal;
      currentVal = "";

      if ((firstTwo[0] < lastTwo[0] && firstTwo[1] > lastTwo[1]) || (firstTwo[0] > lastTwo[0] && firstTwo[1] < lastTwo[1]) || firstTwo[0] == lastTwo[0] || firstTwo[1] == lastTwo[1]) {
        answer++;
      }
      commaPassed = false;
    }
    else { var = 1; }

    for (char c : l) {
      if (c == '-') {
        curVal = std::stoi(currentVal);
        currentVal = "";
        if (commaPassed) {
          lastTwo[0] = curVal;
        }
        else { firstTwo[0] = curVal; }
        continue;
      }
      else if (c == ',') {
        curVal = std::stoi(currentVal);
        currentVal = "";
        commaPassed = true;
        firstTwo[1] = curVal;
        continue;
      }

      currentVal += c;
    } 

  }

  curVal = std::stoi(currentVal);
  lastTwo[1] = curVal;

  if ((firstTwo[0] < lastTwo[0] && firstTwo[1] > lastTwo[1]) || (firstTwo[0] > lastTwo[0] && firstTwo[1] < lastTwo[1]) || firstTwo[0] == lastTwo[0] || firstTwo[1] == lastTwo[1]) {
    answer++;
  }

  std::cout << "The answer is " << answer << std::endl;
}

int main()
{
  Day4Part1();
  return 0;
}