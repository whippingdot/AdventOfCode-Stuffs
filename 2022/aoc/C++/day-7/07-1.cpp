#include "..\aoc.h"

struct extraMap {
  int inte = 0;
  std::map<std::string, extraMap> mapp;
};

void Day7Part1() {
  std::vector<std::string> input =
      read_file("C:"
                "\\Users\\sanja\\OneDrive\\Documents\\Coding\\GitHubProjects\\A"
                "dventOfCode-Stuffs\\2022\\aoc\\C++\\day-7\\input.txt");
  int answer = 0;
  int lastsPos = 0;

  char cmd[2];

  std::string depth = "";
  std::string fun;

  std::map<std::string, extraMap> fs = std::map<std::string, extraMap>();

  for (int i = 0; i < input.size(); i++) {
    for (int j = 0; j < input[i].size(); j++) {
      if (input[i][j] != '$') {
        continue;
      }
      cmd[0] = input[i][2];
      cmd[1] = input[i][3];

      if (cmd == "cd") {
        fun = input[i].substr(5);
        if (fun == "/") {
          depth = "";
        } else if (fun == "..") {
          for (int x = 0; x < depth.size(); x++) {
            if (depth[x] == '/') {
              lastsPos = x;
            }
          }
          depth = depth.substr(0, lastsPos);
        } else {
          depth += '/' + fun;
        }
      } else {
      }
    }
  }
  std::cout << "The answer is " << answer << std::endl;
}

int main() {
  Day7Part1();
  return 0;
}