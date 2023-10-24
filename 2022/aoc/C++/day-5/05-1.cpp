#include "..\aoc.h"

void Day5Part1() {
  std::vector<std::string> input =
      read_file("C:"
                "\\Users\\sanja\\OneDrive\\Documents\\Coding\\GitHubProjects\\A"
                "dventOfCode-Stuffs\\2022\\aoc\\C++\\day-5\\input.txt");
  std::string answer = "";
  std::string num = "";

  int rowCount = 0;
  int rowCount2 = 1;
  int moveValue = 0;
  int fromValue = 0;
  int toValue = 0;
  int iIndex = 0;

  bool instruct = false;
  bool createdVectors = false;
  bool moveDone = false;
  bool space1 = false;
  bool firstDone = false;

  std::vector<std::vector<char>> grid = std::vector<std::vector<char>>();

  for (std::string l : input) {
    for (char c : l) {
      if ((rowCount2 + 2) % 4 == 0) {
        // std::cout << "Reach Here\nRow Count and 2: " << rowCount << " " <<
        // rowCount2 << "\nC: " << c << std::endl;
        if (std::isdigit(c)) {
          instruct = true;
          break;
        }
        if (!createdVectors) {
          grid.push_back(std::vector<char>());
        }
        if (c != ' ') {
          grid[rowCount].push_back(c);
        }
        rowCount++;
      }
      rowCount2++;
    }
    if (instruct) {
      break;
    }
    createdVectors = true;
    rowCount = 0;
    rowCount2 = 1;
  }

  // std::cout << grid.size() << std::endl;

  for (int i = 0; i < grid.size(); i++) {
    std::reverse(grid[i].begin(), grid[i].end());
    // std::cout << grid[i].size() << std::endl;
  }

  instruct = false;

  for (std::string l : input) {
    if (!instruct) {
      if (l == "") {
        instruct = true;
        continue;
      }
      continue;
    } else {
      for (char c : l) {
        // std::cout << "C: " << c << std::endl;
        if (c == ' ') {
          if (space1) {
            if (!moveDone) {
              moveDone = true;
              // std::cout << num << " 1\n";
              moveValue = stoi(num);
            } else {
              // std::cout << num << " 2\n";
              fromValue = stoi(num) - 1;
            }
            space1 = false;
          } else {
            if (!moveDone) {
              space1 = true;
              if (firstDone) {
                // std::cout << num << " 3\n";
                toValue = stoi(num) - 1;
                for (int i = 1; i < moveValue + 1; i++) {
                  iIndex = grid[fromValue].size() - i;
                  // std::cout << grid[fromValue].size() << " and " << iIndex <<
                  // std::endl;
                  grid[toValue].push_back(grid[fromValue][iIndex]);
                }
                for (int i = 0; i < moveValue; i++) {
                  grid[fromValue].pop_back();
                }
              } else {
                firstDone = true;
              }
              num = "";
            } else {
              space1 = true;
              num = "";
            }
          }
        }
        if (std::isdigit(c)) {
          num += c;
        }
      }
    }
    moveDone = false;
    space1 = false;
  }
  toValue = stoi(num) - 1;
  for (int i = 1; i < moveValue + 1; i++) {
    iIndex = grid[fromValue].size() - i;
    // std::cout << grid[fromValue].size() << " and " << iIndex << std::endl;
    grid[toValue].push_back(grid[fromValue][iIndex]);
  }
  for (int i = 0; i < moveValue; i++) {
    grid[fromValue].pop_back();
  }

  for (int i = 0; i < grid.size(); i++) {
    iIndex = grid[i].size() - 1;
    answer += grid[i][iIndex];
  }

  std::cout << "The answer is " << answer << std::endl;
}

int main() {
  Day5Part1();
  return 0;
}