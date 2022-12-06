#include "..\aoc.h"

void Day6Part2()
{
  std::vector<std::string> input = read_file("C:\\Users\\sanja\\OneDrive\\Documents\\Coding\\GitHubProjects\\AdventOfCode-Stuffs\\2022\\aoc\\C++\\day-6\\input.txt");
  int answer = 14;

  std::vector<char> fourteen = std::vector<char>();
  std::map<char, int> mapp = std::map<char, int>();

  bool vectorFilled = false;
  bool found = false;

  for (std::string l : input)
  {
    for (char c : l)
    {
      if (!vectorFilled)
      {
        // std::cout << c << std::endl;
        fourteen.push_back(c);
        if (fourteen.size() == 13)
        {
          vectorFilled = true;
        }
      }
      else
      {
        for (int f = 0; f < 13; f++)
        {
          for (int r = 0; r < 13; r++)
          {
            if (f == r)
            {
              continue;
            }
            // std::cout << fourteen[f] << " and " << fourteen[r] << std::endl;
            if (fourteen[f] == fourteen[r] || c == fourteen[f] || c == fourteen[r])
            {
              found = true;
              break;
            }
          }
          if (found)
          {
            break;
          }
        }
        if (!found)
        {
          break;
        }
        else
        {
          fourteen.erase(fourteen.begin());
          fourteen.push_back(c);
        }
        answer++;
        mapp.clear();
        found = false;
      }
    }
  }

  std::cout << "The answer is " << answer << std::endl;
}

int main()
{
  Day6Part2();
  return 0;
}