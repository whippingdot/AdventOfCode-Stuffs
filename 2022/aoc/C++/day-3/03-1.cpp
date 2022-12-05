#include "..\aoc.h"

void Day3Part1()
{
  std::vector<std::string> input = read_file("C:\\Users\\sanja\\OneDrive\\Documents\\Coding\\GitHubProjects\\AdventOfCode-Stuffs\\2022\\aoc\\C++\\day-3\\input.txt");
  int answer = 0;
  int lineSize = 0;
  int counter = 1;
  int times = 1;

  bool found = false;

  std::vector<char> half = std::vector<char>();
  std::vector<char> oldHalf = std::vector<char>();

  std::map<char, int> priorities = std::map<char, int>();

  priorities = {{'a', 1}, {'b', 2}, {'c', 3}, {'d', 4}, {'e', 5}, {'f', 6}, {'g', 7}, {'h', 8}, {'i', 9}, {'j', 10}, {'k', 11}, {'l', 12}, {'m', 13}, {'n', 14}, {'o', 15}, {'p', 16}, {'q', 17}, {'r', 18}, {'s', 19}, {'t', 20}, {'u', 21}, {'v', 22}, {'w', 23}, {'x', 24}, {'y', 25}, {'z', 26}, {'A', 27}, {'B', 28}, {'C', 29}, {'D', 30}, {'E', 31}, {'F', 32}, {'G', 33}, {'H', 34}, {'I', 35}, {'J', 36}, {'K', 37}, {'L', 38}, {'M', 39}, {'N', 40}, {'O', 41}, {'P', 42}, {'Q', 43}, {'R', 44}, {'S', 45}, {'T', 46}, {'U', 47}, {'V', 48}, {'W', 49}, {'X', 50}, {'Y', 51}, {'Z', 52}};

  for (std::string l : input)
  {
    lineSize = l.size();
    for (char c : l)
    {
      half.push_back(c);
      if (counter == lineSize / 2)
      {
        oldHalf = half;
        half.clear();
      }
      else if (counter == lineSize)
      {
        for (char h : half)
        {
          for (char o : oldHalf)
          {
            if (h == o)
            {
              // std::cout << "Size: " << lineSize << "\nCounter: " << counter << "\nH and O: " << h << " and " << o << "\nTIMES " << times << std::endl;
              answer += priorities[o];
              // std::cout << "ANSWER " << answer << std::endl;
              found = true;
              times++;
              break;
            }
          }
          if (found)
          {
            break;
          }
        }
      }
      counter++;
    }
    counter = 1;
    half.clear();
    oldHalf.clear();
    found = false;
  }

  std::cout << "The answer is " << answer << std::endl;
}

int main()
{
  Day3Part1();
  return 0;
}