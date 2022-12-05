#include "..\aoc.h"

void Day5Part2()
{
  std::vector<std::string> input = read_file("C:\\Users\\sanja\\OneDrive\\Documents\\Coding\\GitHubProjects\\AdventOfCode-Stuffs\\2022\\aoc\\C++\\day-5\\input.txt");
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

  for (std::string l : input)
  {
    for (char c : l)
    {
      if ((rowCount2 + 2) % 4 == 0)
      {
        if (std::isdigit(c))
        {
          instruct = true;
          break;
        }
        if (!createdVectors)
        {
          grid.push_back(std::vector<char>());
        }
        if (c != ' ')
        {
          grid[rowCount].push_back(c);
        }
        rowCount++;
      }
      rowCount2++;
    }
    if (instruct)
    {
      break;
    }
    createdVectors = true;
    rowCount = 0;
    rowCount2 = 1;
  }

  for (int i = 0; i < grid.size(); i++)
  {
    std::reverse(grid[i].begin(), grid[i].end());
  }

  instruct = false;

  for (std::string l : input)
  {
    if (!instruct)
    {
      if (l == "")
      {
        instruct = true;
        continue;
      }
      continue;
    }
    else
    {
      for (char c : l)
      {
        if (c == ' ')
        {
          if (space1)
          {
            if (!moveDone)
            {
              moveDone = true;
              moveValue = stoi(num);
            }
            else
            {
              fromValue = stoi(num) - 1;
            }
            space1 = false;
          }
          else
          {
            if (!moveDone)
            {
              space1 = true;
              if (firstDone)
              {
                toValue = stoi(num) - 1;
                for (int i = moveValue; i > 0; i--)
                {
                  iIndex = grid[fromValue].size() - i;
                  grid[toValue].push_back(grid[fromValue][iIndex]);
                }
                for (int i = 0; i < moveValue; i++)
                {
                  grid[fromValue].pop_back();
                }
              }
              else
              {
                firstDone = true;
              }
              num = "";
            }
            else
            {
              space1 = true;
              num = "";
            }
          }
        }
        if (std::isdigit(c))
        {
          num += c;
        }
      }
    }
    moveDone = false;
    space1 = false;
  }
  toValue = stoi(num) - 1;
  for (int i = moveValue; i > 0; i--)
  {
    iIndex = grid[fromValue].size() - i;
    grid[toValue].push_back(grid[fromValue][iIndex]);
  }
  for (int i = 0; i < moveValue; i++)
  {
    grid[fromValue].pop_back();
  }

  for (int i = 0; i < grid.size(); i++)
  {
    iIndex = grid[i].size() - 1;
    answer += grid[i][iIndex];
  }

  std::cout << "The answer is " << answer << std::endl;
}

int main()
{
  Day5Part2();
  return 0;
}