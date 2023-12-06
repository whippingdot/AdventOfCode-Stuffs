#include "C:\Users\sanja\OneDrive\Documents\Coding\GitHubProjects\AdventOfCode-Stuffs\2023\aoc\aoc.h"

int *findNum(std::vector<std::string> inpute, int xcor, int ycor)
{
  std::vector<char> numbers = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
  int finalNum = 0;
  int arrayy[2] = {0, 0};
  for (int j = ycor; std::find(numbers.begin(), numbers.end(), inpute[xcor][j]) != numbers.end(); j++)
  {
    finalNum = (finalNum * 10) + (int(inpute[xcor][j]) - 48);
    arrayy[1] = j;
  }
  arrayy[0] = finalNum;
  return arrayy;
}

void Day3Part2()
{
  std::vector<char> integers = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
  std::vector<std::string> input = read_file("C:\\Users\\sanja\\OneDrive\\Documents\\Coding\\GitHubProjects\\AdventOfCode-Stuffs\\2023\\aoc\\C++\\day-3\\input.txt");
  int answer = 0;
  int min = 0;
  int counter = 0;
  int omin = 200;
  int *tValues;
  std::string answerS = "";
  std::vector<int> numbers = std::vector<int>();

  for (int x = 0; x < input.size(); x++)
  {
    for (int y = 0; y < input[x].size(); y++)
    {
      if (input[x][y] == '*')
      {
        // Below comented code ended up all being useless since there was no asterix on the edge or corner
        // if (x != 0 && !(x == (input.size() - 1)) && !(y == (input[x].size() - 1)) && y != 0)
        //{
        for (int a = x - 1; a <= x + 1; a++)
        {
          for (int b = y - 1; b <= y + 1; b++)
          {
            if (std::find(integers.begin(), integers.end(), input[a][b]) != integers.end())
            {
              for (int l = b; std::find(integers.begin(), integers.end(), input[a][l]) != integers.end(); l--)
              {
                min = l;
              }
              if (min != omin)
              {
                tValues = findNum(input, a, min);
                numbers.push_back(tValues[0]);
              }
              omin = min;
            }
          }
          omin = 200;
        }
        //}
        // else if (x == 0 && !(y == (input[x].size() - 1)) && y != 0)
        //{
        //  for (int a = x; a <= x + 1; a++) {
        //    for (int b = y - 1; b <= y + 1; b++) {
        //      if (std::find(integers.begin(), integers.end(), input[a][b]) != integers.end()) {
        //        for (int l = b; std::find(integers.begin(), integers.end(), input[a][l]) != integers.end(); l--) {
        //          min = l;
        //        }
        //        if (min != omin) {
        //          tValues = findNum(input, a, min);
        //          numbers.push_back(tValues[0]);
        //        }
        //        omin = min;
        //      }
        //    }
        //    omin = 200;
        //  }
        //}
        // else if (x == (input.size() - 1) && !(y == (input[x].size() - 1)) && y != 0)
        //{
        //  for (int a = x - 1; a <= x; a++) {
        //    for (int b = y - 1; b <= y + 1; b++) {
        //      if (std::find(integers.begin(), integers.end(), input[a][b]) != integers.end()) {
        //        for (int l = b; std::find(integers.begin(), integers.end(), input[a][l]) != integers.end(); l--) {
        //          min = l;
        //        }
        //        if (min != omin) {
        //          tValues = findNum(input, a, min);
        //          numbers.push_back(tValues[0]);
        //        }
        //        omin = min;
        //      }
        //    }
        //    omin = 200;
        //  }
        //}
        // else if (x != 0 && !(x == (input.size() - 1)) && y == 0)
        //{
        //  for (int a = x - 1; a <= x + 1; a++) {
        //    for (int b = y; b <= y + 1; b++) {
        //      if (std::find(integers.begin(), integers.end(), input[a][b]) != integers.end()) {
        //        for (int l = b; std::find(integers.begin(), integers.end(), input[a][l]) != integers.end(); l--) {
        //          min = l;
        //        }
        //        if (min != omin) {
        //          tValues = findNum(input, a, min);
        //          numbers.push_back(tValues[0]);
        //        }
        //        omin = min;
        //      }
        //    }
        //    omin = 200;
        //  }
        //}
        // else if (x != 0 && !(x == (input.size() - 1)) && y == (input[x].size() - 1))
        //{
        //  for (int a = x - 1; a <= x + 1; a++) {
        //    for (int b = y - 1; b <= y; b++) {
        //      if (std::find(integers.begin(), integers.end(), input[a][b]) != integers.end()) {
        //        for (int l = b; std::find(integers.begin(), integers.end(), input[a][l]) != integers.end(); l--) {
        //          min = l;
        //        }
        //        if (min != omin) {
        //          tValues = findNum(input, a, min);
        //          numbers.push_back(tValues[0]);
        //        }
        //        omin = min;
        //      }
        //    }
        //    omin = 200;
        //  }
        //}
        // else if (x == 0 && y == 0)
        //{
        //  for (int a = x; a <= x + 1; a++) {
        //    for (int b = y; b <= y + 1; b++) {
        //      if (std::find(integers.begin(), integers.end(), input[a][b]) != integers.end()) {
        //        for (int l = b; std::find(integers.begin(), integers.end(), input[a][l]) != integers.end(); l--) {
        //          min = l;
        //        }
        //        if (min != omin) {
        //          tValues = findNum(input, a, min);
        //          numbers.push_back(tValues[0]);
        //        }
        //        omin = min;
        //      }
        //    }
        //    omin = 200;
        //  }
        //}
        // else if (x == 0 && y == (input[x].size() - 1))
        //{
        //  for (int a = x; a <= x + 1; a++) {
        //    for (int b = y - 1; b <= y; b++) {
        //      if (std::find(integers.begin(), integers.end(), input[a][b]) != integers.end()) {
        //        for (int l = b; std::find(integers.begin(), integers.end(), input[a][l]) != integers.end(); l--) {
        //          min = l;
        //        }
        //        if (min != omin) {
        //          tValues = findNum(input, a, min);
        //          numbers.push_back(tValues[0]);
        //        }
        //        omin = min;
        //      }
        //    }
        //    omin = 200;
        //  }
        //}
        // else if (x == (input.size() - 1) && y == 0)
        //{
        //  for (int a = x - 1; a <= x; a++) {
        //    for (int b = y; b <= y + 1; b++) {
        //      if (std::find(integers.begin(), integers.end(), input[a][b]) != integers.end()) {
        //        for (int l = b; std::find(integers.begin(), integers.end(), input[a][l]) != integers.end(); l--) {
        //          min = l;
        //        }
        //        if (min != omin) {
        //          tValues = findNum(input, a, min);
        //          numbers.push_back(tValues[0]);
        //        }
        //        omin = min;
        //      }
        //    }
        //    omin = 200;
        //  }
        //}
        // else if (x == (input.size() - 1) && (y == input[x].size() - 1))
        //{
        //  for (int a = x - 1; a <= x; a++) {
        //    for (int b = y - 1; b <= y; b++) {
        //      if (std::find(integers.begin(), integers.end(), input[a][b]) != integers.end()) {
        //        for (int l = b; std::find(integers.begin(), integers.end(), input[a][l]) != integers.end(); l--) {
        //          min = l;
        //        }
        //        if (min != omin) {
        //          tValues = findNum(input, a, min);
        //          numbers.push_back(tValues[0]);
        //        }
        //        omin = min;
        //      }
        //    }
        //    omin = 200;
        //  }
        //}
        if (numbers.size() == 2)
        {
          answer = answer + (numbers[0] * numbers[1]);
        }
        numbers.clear();
      }
    }
  }

  std::cout << "The answer is " << answer << std::endl;
}

int main()
{
  Day3Part2();
  return 0;
}