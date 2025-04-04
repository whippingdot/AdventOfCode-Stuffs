#include "C:\Users\sanja\OneDrive\Documents\Coding\GitHubProjects\AdventOfCode-Stuffs\2023\aoc\aoc.h"

void Day10Part1()
{
  std::vector<std::string> input =
      read_file("C:\\Users\\sanja\\OneDrive\\Documents\\Coding\\GitHubProjects\\AdventOfCode-Stuffs\\2023\\aoc\\C++\\day-10\\input.txt");
  std::vector<char> letters = std::vector<char>();
  int answer = 0;
  int sRow = 0;
  int sColumn = 0;
  int row = 0;
  int column = 0;
  int steps = 0;
  bool west = false;
  bool north = false;
  bool south = false;

  for (int i = 0; i < input.size(); i++)
  {
    for (int j = 0; j < input[i].size(); j++)
    {
      if (input[i][j] == 'S')
      {
        sRow = i;
        sColumn = j;
        break;
      }
    }
    if (sRow != 0)
    {
      break;
    }
  }

  while (row != sRow || column != sColumn)
  {
    std::cout << "Here\n";
    if (steps == 0)
    {
      row = sRow;
      column = sColumn;

      if (input[row + 1][column] == '|')
      {
        row += 2;
        north = true;
        letters.push_back('|');
      }
      else if (input[row + 1][column] == 'L')
      {
        row++;
        column++;
        north = true;
        letters.push_back('L');
      }
      else if (input[row + 1][column] == 'J')
      {
        row++;
        column--;
        north = true;
        letters.push_back('J');
      }
      else if (input[row][column + 1] == '-')
      {
        column += 2;
        west = true;
        letters.push_back('-');
      }
      else if (input[row][column + 1] == 'J')
      {
        row--;
        column++;
        west = true;
        letters.push_back('J');
      }
      else if (input[row][column + 1] == '7')
      {
        row++;
        column++;
        west = true;
        letters.push_back('7');
      }
      else if (input[row - 1][column] == '|')
      {
        row -= 2;
        south = true;
        letters.push_back('|');
      }
      else if (input[row - 1][column] == '7')
      {
        row--;
        column--;
        south = true;
        letters.push_back('7');
      }
      else if (input[row - 1][column] == 'F')
      {
        row--;
        column++;
        south = true;
        letters.push_back('F');
      }
      else if (input[row][column - 1] == '-')
      {
        column -= 2;
        letters.push_back('-');
      }
      else if (input[row][column - 1] == 'F')
      {
        row++;
        column--;
        letters.push_back('F');
      }
      else if (input[row][column - 1] == 'L')
      {
        row--;
        column--;
        letters.push_back('L');
      }
      steps++;
      std::cout << row << " " << column << std::endl;
      std::cout << sRow << " " << sColumn << std::endl;
      continue;
    }
    letters.push_back(input[row][column]);
    switch (input[row][column])
    {
    case '|':
      if (north)
      {
        row++;
      }
      else
      {
        row--;
      }
      break;
    case '-':
      if (west)
      {
        column++;
      }
      else
      {
        column--;
      }
      break;
    case 'J':
      if (north)
      {
        column--;
        north = false;
      }
      else
      {
        row--;
        south = true;
        west = false;
      }
      break;
    case 'L':
      if (north)
      {
        column++;
        north = false;
        west = true;
      }
      else
      {
        row--;
        south = true;
      }
      break;
    case '7':
      if (west)
      {
        row++;
        west = false;
        north = true;
      }
      else
      {
        column--;
        south = false;
      }
      break;
    case 'F':
      if (south)
      {
        column++;
        south = false;
        west = true;
      }
      else
      {
        row++;
        north = true;
      }
      break;
    default:
      break;
    }
    steps++;
  }

  answer = ((letters.size() - 1) / 2) + 1;

  std::cout << std::format("It takes {} steps to get from the starting point to the point farthest from the starting point", answer) << std::endl;
}

int main()
{
  Day10Part1();
  return 0;
}