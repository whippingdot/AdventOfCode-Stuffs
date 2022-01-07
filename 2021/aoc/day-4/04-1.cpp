#include "../aoc.h"

void Day4Part2()
{
  vector<string> input = read_file("input.txt");
  int answer = 0;

  int lineCounter = 0;
  int charCounter = 0;
  int sheetHelperCounter = 0;

  int bingoSheets[100][5][5];

  vector<char> charVector = vector<char>();
  vector<int> bingoNumbers = vector<int>();

  string tempVal = "";
  int iTempVal = 0;
  char *str;

  for (string &line : input)
  {
    if (sheetHelperCounter = 5)
    {
      sheetHelperCounter = 0;
    }

    if (line == "\n")
    {
      continue;
    }

    if (lineCounter == 0)
    {
      for (char &character : line)
      {
        charVector.push_back(character);
      }
      for (int i = 0; i < charVector.size(); i++)
      {
        if ((i + 1) == charVector.size())
        {
          continue;
        }

        if (i - 1 != -1)
        {
          if ((charVector[i] == '1' || charVector[i] == '2' || charVector[i] == '3' || charVector[i] == '4' || charVector[i] == '5' || charVector[i] == '6' || charVector[i] == '7' || charVector[i] == '8' || charVector[i] == '9') && (charVector[i + 1] == '1' || charVector[i + 1] == '2' || charVector[i + 1] == '3' || charVector[i + 1] == '4' || charVector[i + 1] == '5' || charVector[i + 1] == '6' || charVector[i + 1] == '7' || charVector[i + 1] == '8' || charVector[i + 1] == '9'))
          {
            tempVal = charVector[i] + "" + charVector[i + 1];
            cout << charVector[i] - '0' << endl;
            cout << typeid(charVector[i + 1] - '0').name() << endl;
            cout << tempVal << endl;

            // iTempVal = stoi(tempVal);
            bingoNumbers.push_back(iTempVal);
          }
          else if ((charVector[i] == '1' || charVector[i] == '2' || charVector[i] == '3' || charVector[i] == '4' || charVector[i] == '5' || charVector[i] == '6' || charVector[i] == '7' || charVector[i] == '8' || charVector[i] == '9') && !(charVector[i - 1] == '1' || charVector[i - 1] == '2' || charVector[i - 1] == '3' || charVector[i - 1] == '4' || charVector[i - 1] == '5' || charVector[i - 1] == '6' || charVector[i - 1] == '7' || charVector[i - 1] == '8' || charVector[i - 1] == '9'))
          {
            bingoNumbers.push_back(charVector[i] - '0');
          }
          else
          {
            continue;
          }
        }
        else
        {
          if ((charVector[i] == '1' || charVector[i] == '2' || charVector[i] == '3' || charVector[i] == '4' || charVector[i] == '5' || charVector[i] == '6' || charVector[i] == '7' || charVector[i] == '8' || charVector[i] == '9') && (charVector[i + 1] == '1' || charVector[i + 1] == '2' || charVector[i + 1] == '3' || charVector[i + 1] == '4' || charVector[i + 1] == '5' || charVector[i + 1] == '6' || charVector[i + 1] == '7' || charVector[i + 1] == '8' || charVector[i + 1] == '9'))
          {
            tempVal = charVector[i] + charVector[i + 1];
            // iTempVal = stoi(tempVal);
            bingoNumbers.push_back(iTempVal);
          }
          else if (charVector[i] == '1' || charVector[i] == '2' || charVector[i] == '3' || charVector[i] == '4' || charVector[i] == '5' || charVector[i] == '6' || charVector[i] == '7' || charVector[i] == '8' || charVector[i] == '9')
          {
            bingoNumbers.push_back(charVector[i] - '0');
          }
          else
          {
            continue;
          }
        }
      }
    }

    charCounter = 0;
    for (char &character : line)
    {
      bingoSheets[0][lineCounter][charCounter] = character;
      charCounter++;
    }
    lineCounter++;
    sheetHelperCounter++;
  }

  cout << "The answer is " << answer << endl;
}

int main()
{
  Day4Part2();
  return 0;
}