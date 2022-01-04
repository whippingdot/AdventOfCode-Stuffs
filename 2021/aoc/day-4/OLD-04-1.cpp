#include "../aoc.h"

void Day4Part1()
{
  vector<string> input = read_file("input.txt");
  int answer = 0;
  int lineNumber = 0;

  string line1 = "";
  string line2 = "";
  string line3 = "";
  string line4 = "";
  string line5 = "";

  int iLine1 = 0;
  int iLine2 = 0;
  int iLine3 = 0;
  int iLine4 = 0;
  int iLine5 = 0;

  for (string &line : input)
  {
    if (line == "94,21,58,16,4,1,44,6,17,48,20,92,55,36,40,63,62,2,47,7,46,72,85,24,66,49,34,56,98,41,84,23,86,64,28,90,39,97,73,81,12,69,35,26,75,8,32,77,52,50,5,96,14,31,70,60,29,71,9,68,19,65,99,57,54,61,33,91,27,78,43,95,42,3,88,51,53,30,89,87,93,74,18,15,80,38,82,79,0,22,13,67,59,11,83,76,10,37,25,45")
    {
      lineNumber++;
      continue;
    }
    else if (line == "")
    {
      lineNumber++;
      continue;
    }
    else if (line == " ") {
      for ()
  int array[5][5] = {[line1], [line2], [line3], [line4], [line5]};
    }

    if (lineNumber % 6 == 3)
    {
      for (char &c : line)
      {
        if (c != ' ')
        {
          line1 += (c - '0') + ", ";
        }
      }
      line1 = line;
    }
    else if (lineNumber % 6 == 4)
    {
      line2 = line;
    }
    else if (lineNumber % 6 == 5)
    {
      line3 = line;
    }
    else if (lineNumber % 6 == 0)
    {
      line4 = line;
    }
    else if (lineNumber % 6 == 1)
    {
      line5 = line;
    }
  }

  cout << "The answer is " << answer << endl;
}

int main()
{
  Day4Part1();
  return 0;
}