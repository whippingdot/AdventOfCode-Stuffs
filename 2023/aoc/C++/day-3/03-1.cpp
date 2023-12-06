#include "C:\Users\sanja\OneDrive\Documents\Coding\GitHubProjects\AdventOfCode-Stuffs\2023\aoc\aoc.h"

void Day3Part1()
{
  std::vector<std::string> input = read_file("C:\\Users\\sanja\\OneDrive\\Documents\\Coding\\GitHubProjects\\AdventOfCode-Stuffs\\2023\\aoc\\C++\\day-3\\input.txt");
  int answer = 0;
  int max = 0;
  std::string answerS = "";
  std::vector<char> integers = std::vector<char>();
  std::vector<char> numbers = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
  bool specTouch = false;

  for (int x = 0; x < input.size(); x++)
  {
    for (int y = 0; y < input[x].size(); y++)
    {
      if (std::find(numbers.begin(), numbers.end(), input[x][y]) != numbers.end())
      {
        for (int z = y; std::find(numbers.begin(), numbers.end(), input[x][z]) != numbers.end(); z++)
        {
          integers.push_back(input[x][z]);
          max = z;
          if (!specTouch)
          {
            if (x != 0 && !(x == (input.size() - 1)) && !(z == (input[x].size() - 1)) && z != 0)
            {
              if (((std::find(numbers.begin(), numbers.end(), input[x - 1][z - 1]) == numbers.end()) && (input[x - 1][z - 1] != '.')) || ((std::find(numbers.begin(), numbers.end(), input[x - 1][z]) == numbers.end()) && (input[x - 1][z] != '.')) || ((std::find(numbers.begin(), numbers.end(), input[x - 1][z + 1]) == numbers.end()) && (input[x - 1][z + 1] != '.')) || ((std::find(numbers.begin(), numbers.end(), input[x][z - 1]) == numbers.end()) && (input[x][z - 1] != '.')) || ((std::find(numbers.begin(), numbers.end(), input[x][z + 1]) == numbers.end()) && (input[x][z + 1] != '.')) || ((std::find(numbers.begin(), numbers.end(), input[x + 1][z - 1]) == numbers.end()) && (input[x + 1][z - 1] != '.')) || ((std::find(numbers.begin(), numbers.end(), input[x + 1][z]) == numbers.end()) && (input[x + 1][z] != '.')) || ((std::find(numbers.begin(), numbers.end(), input[x + 1][z + 1]) == numbers.end()) && (input[x + 1][z + 1] != '.')))
              {
                specTouch = true;
              }
            }
            else if (x == 0 && !(z == (input[x].size() - 1)) && z != 0)
            {
              if (((std::find(numbers.begin(), numbers.end(), input[x][z - 1]) == numbers.end()) && (input[x][z - 1] != '.')) || ((std::find(numbers.begin(), numbers.end(), input[x][z + 1]) == numbers.end()) && (input[x][z + 1] != '.')) || ((std::find(numbers.begin(), numbers.end(), input[x + 1][z - 1]) == numbers.end()) && (input[x + 1][z - 1] != '.')) || ((std::find(numbers.begin(), numbers.end(), input[x + 1][z]) == numbers.end()) && (input[x + 1][z] != '.')) || ((std::find(numbers.begin(), numbers.end(), input[x + 1][z + 1]) == numbers.end()) && (input[x + 1][z + 1] != '.')))
              {
                specTouch = true;
              }
            }
            else if (x == (input.size() - 1) && !(z == (input[x].size() - 1)) && z != 0)
            {
              if (((std::find(numbers.begin(), numbers.end(), input[x - 1][z - 1]) == numbers.end()) && (input[x - 1][z - 1] != '.')) || ((std::find(numbers.begin(), numbers.end(), input[x - 1][z]) == numbers.end()) && (input[x - 1][z] != '.')) || ((std::find(numbers.begin(), numbers.end(), input[x - 1][z + 1]) == numbers.end()) && (input[x - 1][z + 1] != '.')) || ((std::find(numbers.begin(), numbers.end(), input[x][z - 1]) == numbers.end()) && (input[x][z - 1] != '.')) || ((std::find(numbers.begin(), numbers.end(), input[x][z + 1]) == numbers.end()) && (input[x][z + 1] != '.')))
              {
                specTouch = true;
              }
            }
            else if (x != 0 && !(x == (input.size() - 1)) && z == 0)
            {
              if (((std::find(numbers.begin(), numbers.end(), input[x - 1][z]) == numbers.end()) && (input[x - 1][z] != '.')) || ((std::find(numbers.begin(), numbers.end(), input[x - 1][z + 1]) == numbers.end()) && (input[x - 1][z + 1] != '.')) || ((std::find(numbers.begin(), numbers.end(), input[x][z + 1]) == numbers.end()) && (input[x][z + 1] != '.')) || ((std::find(numbers.begin(), numbers.end(), input[x + 1][z]) == numbers.end()) && (input[x + 1][z] != '.')) || ((std::find(numbers.begin(), numbers.end(), input[x + 1][z + 1]) == numbers.end()) && (input[x + 1][z + 1] != '.')))
              {
                specTouch = true;
              }
            }
            else if (x != 0 && !(x == (input.size() - 1)) && z == (input[x].size() - 1))
            {
              if (((std::find(numbers.begin(), numbers.end(), input[x - 1][z - 1]) == numbers.end()) && (input[x - 1][z - 1] != '.')) || ((std::find(numbers.begin(), numbers.end(), input[x - 1][z]) == numbers.end()) && (input[x - 1][z] != '.')) || ((std::find(numbers.begin(), numbers.end(), input[x][z - 1]) == numbers.end()) && (input[x][z - 1] != '.')) || ((std::find(numbers.begin(), numbers.end(), input[x + 1][z - 1]) == numbers.end()) && (input[x + 1][z - 1] != '.')) || ((std::find(numbers.begin(), numbers.end(), input[x + 1][z]) == numbers.end()) && (input[x + 1][z] != '.')))
              {
                specTouch = true;
              }
            }
            else if (x == 0 && z == 0)
            {
              if (((std::find(numbers.begin(), numbers.end(), input[x][z + 1]) == numbers.end()) && (input[x][z + 1] != '.')) || ((std::find(numbers.begin(), numbers.end(), input[x + 1][z]) == numbers.end()) && (input[x + 1][z] != '.')) || ((std::find(numbers.begin(), numbers.end(), input[x + 1][z + 1]) == numbers.end()) && (input[x + 1][z + 1] != '.')))
              {
                specTouch = true;
              }
            }
            else if (x == 0 && z == (input[x].size() - 1))
            {
              if (((std::find(numbers.begin(), numbers.end(), input[x][z - 1]) == numbers.end()) && (input[x][z - 1] != '.')) || ((std::find(numbers.begin(), numbers.end(), input[x + 1][z - 1]) == numbers.end()) && (input[x + 1][z - 1] != '.')) || ((std::find(numbers.begin(), numbers.end(), input[x + 1][z]) == numbers.end()) && (input[x + 1][z] != '.')))
              {
                specTouch = true;
              }
            }
            else if (x == (input.size() - 1) && z == 0)
            {
              if (((std::find(numbers.begin(), numbers.end(), input[x - 1][z]) == numbers.end()) && (input[x - 1][z] != '.')) || ((std::find(numbers.begin(), numbers.end(), input[x - 1][z + 1]) == numbers.end()) && (input[x - 1][z + 1] != '.')) || ((std::find(numbers.begin(), numbers.end(), input[x][z + 1]) == numbers.end()) && (input[x][z + 1] != '.')))
              {
                specTouch = true;
              }
            }
            else if (x == (input.size() - 1) && (z == input[x].size() - 1))
            {
              if (((std::find(numbers.begin(), numbers.end(), input[x - 1][z - 1]) == numbers.end()) && (input[x - 1][z - 1] != '.')) || ((std::find(numbers.begin(), numbers.end(), input[x - 1][z]) == numbers.end()) && (input[x - 1][z] != '.')) || ((std::find(numbers.begin(), numbers.end(), input[x][z - 1]) == numbers.end()) && (input[x][z - 1] != '.')))
              {
                specTouch = true;
              }
            }
          }
        }
        y = max;
        if (specTouch)
        {
          for (int i = 0; i < integers.size(); i++)
          {
            answerS += integers[i];
          }
          answer += std::stoi(answerS);
          answerS = "";
          specTouch = false;
        }
        integers.clear();
      }
    }
  }

  std::cout << "The answer is " << answer << std::endl;
}

int main()
{
  Day3Part1();
  return 0;
}