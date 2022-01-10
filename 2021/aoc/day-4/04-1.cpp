#include "../aoc.h"

void Day4Part2()
{
  vector<string> input = read_file("input.txt");
  int answer = 0;

  int sheetCounter = 0;
  int lineCounter = 0;
  int charCounter = 0;
  int sheetHelperCounter = 0;

  int bingoSheets[100][5][5];

  vector<char> charVector = vector<char>();
  vector<int> bingoNumbers = vector<int>();

  char tempVal[3];
  int i2 = 0;
  int iTempVal = 0;

  for (string &line : input)
  {
    if (sheetHelperCounter = 5)
    {
      sheetHelperCounter = 0;
      sheetCounter++;
    }

    if (line == "\n")
    {
      continue;
    }

    if (lineCounter == 0)
    {
      charVector.clear();
      for (char &character : line)
      {
        charVector.push_back(character);
      }

      for (int i = 0; i < charVector.size(); i++)
      {
        if ((i + 1) == charVector.size())
        {
          if (!(charVector[i - 1] == '0' || charVector[i - 1] == '1' || charVector[i - 1] == '2' || charVector[i - 1] == '3' || charVector[i - 1] == '4' || charVector[i - 1] == '5' || charVector[i - 1] == '6' || charVector[i - 1] == '7' || charVector[i - 1] == '8' || charVector[i - 1] == '9'))
          {
            bingoNumbers.push_back(charVector[i] - '0');
          }
          continue;
        }

        if (i - 1 != -1)
        {
          if ((charVector[i] == '0' || charVector[i] == '1' || charVector[i] == '2' || charVector[i] == '3' || charVector[i] == '4' || charVector[i] == '5' || charVector[i] == '6' || charVector[i] == '7' || charVector[i] == '8' || charVector[i] == '9') && (charVector[i + 1] == '0' || charVector[i + 1] == '1' || charVector[i + 1] == '2' || charVector[i + 1] == '3' || charVector[i + 1] == '4' || charVector[i + 1] == '5' || charVector[i + 1] == '6' || charVector[i + 1] == '7' || charVector[i + 1] == '8' || charVector[i + 1] == '9'))
          {
            i2 = i + 1;
            tempVal[0] = charVector[i];
            tempVal[1] = charVector[i2];
            tempVal[2] = '\0';
            iTempVal = stoi(tempVal);
            cout << iTempVal << endl;
            bingoNumbers.push_back(iTempVal);
          }
          else if ((charVector[i] == '0' || charVector[i] == '1' || charVector[i] == '2' || charVector[i] == '3' || charVector[i] == '4' || charVector[i] == '5' || charVector[i] == '6' || charVector[i] == '7' || charVector[i] == '8' || charVector[i] == '9') && !(charVector[i - 1] == '0' || charVector[i - 1] == '1' || charVector[i - 1] == '2' || charVector[i - 1] == '3' || charVector[i - 1] == '4' || charVector[i - 1] == '5' || charVector[i - 1] == '6' || charVector[i - 1] == '7' || charVector[i - 1] == '8' || charVector[i - 1] == '9'))
          {
            bingoNumbers.push_back(charVector[i] - '0');
            cout << charVector[i] - '0' << endl;
          }
          else
          {
            continue;
          }
        }
        else
        {
          if ((charVector[i] == '0' || charVector[i] == '1' || charVector[i] == '2' || charVector[i] == '3' || charVector[i] == '4' || charVector[i] == '5' || charVector[i] == '6' || charVector[i] == '7' || charVector[i] == '8' || charVector[i] == '9') && (charVector[i + 1] == '0' || charVector[i + 1] == '1' || charVector[i + 1] == '2' || charVector[i + 1] == '3' || charVector[i + 1] == '4' || charVector[i + 1] == '5' || charVector[i + 1] == '6' || charVector[i + 1] == '7' || charVector[i + 1] == '8' || charVector[i + 1] == '9'))
          {
            i2 = i + 1;
            tempVal[0] = charVector[i];
            tempVal[1] = charVector[i2];
            tempVal[2] = '\0';
            iTempVal = stoi(tempVal);
            cout << iTempVal << endl;
            bingoNumbers.push_back(iTempVal);
          }
          else if (charVector[i] == '0' || charVector[i] == '1' || charVector[i] == '2' || charVector[i] == '3' || charVector[i] == '4' || charVector[i] == '5' || charVector[i] == '6' || charVector[i] == '7' || charVector[i] == '8' || charVector[i] == '9')
          {
            bingoNumbers.push_back(charVector[i] - '0');
            cout << charVector[i] - '0' << endl;
          }
          else
          {
            continue;
          }
        }
      }
      lineCounter++;
      continue;
    }

    charCounter = 0;

    charVector.clear();
    for (char &character : line)
    {
      charVector.push_back(character);
    }

    for (int i = 0; i < charVector.size(); i++)
    {
      if ((i + 1) == charVector.size())
      {
        if (!(charVector[i - 1] == '0' || charVector[i - 1] == '1' || charVector[i - 1] == '2' || charVector[i - 1] == '3' || charVector[i - 1] == '4' || charVector[i - 1] == '5' || charVector[i - 1] == '6' || charVector[i - 1] == '7' || charVector[i - 1] == '8' || charVector[i - 1] == '9'))
        {
          bingoSheets[sheetCounter][sheetHelperCounter][charCounter] = charVector[i] - '0';
          cout << bingoSheets[sheetCounter][sheetHelperCounter][charCounter] << endl;
          charCounter++;
        }
        continue;
      }

      if (i - 1 != -1)
      {
        if ((charVector[i] == '0' || charVector[i] == '1' || charVector[i] == '2' || charVector[i] == '3' || charVector[i] == '4' || charVector[i] == '5' || charVector[i] == '6' || charVector[i] == '7' || charVector[i] == '8' || charVector[i] == '9') && (charVector[i + 1] == '0' || charVector[i + 1] == '1' || charVector[i + 1] == '2' || charVector[i + 1] == '3' || charVector[i + 1] == '4' || charVector[i + 1] == '5' || charVector[i + 1] == '6' || charVector[i + 1] == '7' || charVector[i + 1] == '8' || charVector[i + 1] == '9'))
        {
          i2 = i + 1;
          tempVal[0] = charVector[i];
          tempVal[1] = charVector[i2];
          tempVal[2] = '\0';
          iTempVal = stoi(tempVal);
          bingoSheets[sheetCounter][sheetHelperCounter][charCounter] = iTempVal;
          cout << bingoSheets[sheetCounter][sheetHelperCounter][charCounter] << endl;
        }
        else if ((charVector[i] == '0' || charVector[i] == '1' || charVector[i] == '2' || charVector[i] == '3' || charVector[i] == '4' || charVector[i] == '5' || charVector[i] == '6' || charVector[i] == '7' || charVector[i] == '8' || charVector[i] == '9') && !(charVector[i - 1] == '0' || charVector[i - 1] == '1' || charVector[i - 1] == '2' || charVector[i - 1] == '3' || charVector[i - 1] == '4' || charVector[i - 1] == '5' || charVector[i - 1] == '6' || charVector[i - 1] == '7' || charVector[i - 1] == '8' || charVector[i - 1] == '9'))
        {
          bingoSheets[sheetCounter][sheetHelperCounter][charCounter] = charVector[i] - '0';
          cout << bingoSheets[sheetCounter][sheetHelperCounter][charCounter] << endl;
        }
        else
        {
          continue;
        }
      }
      else
      {
        if ((charVector[i] == '0' || charVector[i] == '1' || charVector[i] == '2' || charVector[i] == '3' || charVector[i] == '4' || charVector[i] == '5' || charVector[i] == '6' || charVector[i] == '7' || charVector[i] == '8' || charVector[i] == '9') && (charVector[i + 1] == '0' || charVector[i + 1] == '1' || charVector[i + 1] == '2' || charVector[i + 1] == '3' || charVector[i + 1] == '4' || charVector[i + 1] == '5' || charVector[i + 1] == '6' || charVector[i + 1] == '7' || charVector[i + 1] == '8' || charVector[i + 1] == '9'))
        {
          i2 = i + 1;
          tempVal[0] = charVector[i];
          tempVal[1] = charVector[i2];
          tempVal[2] = '\0';
          iTempVal = stoi(tempVal);
          bingoSheets[sheetCounter][sheetHelperCounter][charCounter] = iTempVal;
          cout << bingoSheets[sheetCounter][sheetHelperCounter][charCounter] << endl;
        }
        else if (charVector[i] == '0' || charVector[i] == '1' || charVector[i] == '2' || charVector[i] == '3' || charVector[i] == '4' || charVector[i] == '5' || charVector[i] == '6' || charVector[i] == '7' || charVector[i] == '8' || charVector[i] == '9')
        {
          bingoSheets[sheetCounter][sheetHelperCounter][charCounter] = charVector[i] - '0';
          cout << bingoSheets[sheetCounter][sheetHelperCounter][charCounter] << endl;
        }
        else
        {
          continue;
        }
      }
      charCounter++;
    }
    lineCounter++;
    sheetHelperCounter++;
  }

  for (int a : bingoNumbers)
  {
    cout << a << ", ";
  }
  cout << endl;

  for (int x = 0; x < 100; x++)
  {
    for (int y = 0; y < 5; y++)
    {
      for (int z = 0; z < 5; z++)
      {
        cout << bingoSheets[x][y][z];
      }
    }
  }

  // cout << "The answer is " << answer << endl;
}

int main()
{
  Day4Part2();
  return 0;
}