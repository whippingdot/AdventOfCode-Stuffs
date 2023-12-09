#include "C:\Users\sanja\OneDrive\Documents\Coding\GitHubProjects\AdventOfCode-Stuffs\2023\aoc\aoc.h"

int found(std::string hand, char card)
{
  int foun = 0;
  for (char &c : hand)
  {
    if (card == c)
    {
      foun++;
    }
  }
  return foun;
}

void Day7Part1()
{
  std::vector<std::string> input =
      read_file("C:\\Users\\sanja\\OneDrive\\Documents\\Coding\\GitHubProjects\\AdventOfCode-Stuffs\\2023\\aoc\\C++\\day-7\\input.txt");
  std::vector<std::string> cards = std::vector<std::string>();
  std::vector<std::vector<int>> numbers = std::vector<std::vector<int>>();
  std::vector<int> numerals = {0, 0, 0, 0, 0, 0, 0};
  std::list<int> shuffled{0};
  std::list<int>::iterator it = shuffled.begin();
  std::string stringy = "";
  std::string tStringy = "";
  char oldC = ' ';
  int answer = 0;
  bool threeCaught = false;
  bool twoCaught = false;
  bool twoCaughtS = false;
  bool founde = false;
  bool inserted = false;

  for (int i = 0; i < input.size(); i++)
  {
    for (int j = 0; j < 5; j++)
    {
      stringy += input[i][j];
      switch (input[i][j])
      {
      case 'A':
        numerals[j + 1] = 13;
        break;
      case 'K':
        numerals[j + 1] = 12;
        break;
      case 'Q':
        numerals[j + 1] = 11;
        break;
      case 'J':
        numerals[j + 1] = 10;
        break;
      case 'T':
        numerals[j + 1] = 9;
        break;
      case '9':
        numerals[j + 1] = 8;
        break;
      case '8':
        numerals[j + 1] = 7;
        break;
      case '7':
        numerals[j + 1] = 6;
        break;
      case '6':
        numerals[j + 1] = 5;
        break;
      case '5':
        numerals[j + 1] = 4;
        break;
      case '4':
        numerals[j + 1] = 3;
        break;
      case '3':
        numerals[j + 1] = 2;
        break;
      case '2':
        numerals[j + 1] = 1;
        break;
      default:
        break;
      }
    }
    cards.push_back(stringy);
    for (int j = 6; j < input[i].size(); j++)
    {
      tStringy += input[i][j];
    }
    numerals[6] = std::stoi(tStringy);
    numbers.push_back(numerals);
    stringy = "";
    tStringy = "";
  }

  for (int i = 0; i < cards.size(); i++)
  {
    for (char c : cards[i])
    {
      switch (found(cards[i], c))
      {
      case 5:
        numbers[i][0] = 7;
        founde = true;
        break;
      case 4:
        numbers[i][0] = 6;
        founde = true;
        break;
      case 3:
        threeCaught = true;
        break;
      case 2:
        if (twoCaught && oldC != c)
        {
          twoCaughtS = true;
        }
        else
        {
          twoCaught = true;
          oldC = c;
        }
        break;
      default:
        break;
      }
      if (founde)
      {
        break;
      }
      else if (twoCaught && threeCaught)
      {
        numbers[i][0] = 5;
        break;
      }
      else if (twoCaught && twoCaughtS)
      {
        numbers[i][0] = 3;
        break;
      }
    }
    if (twoCaught && !twoCaughtS && !threeCaught)
    {
      numbers[i][0] = 2;
    }
    else if (threeCaught && !twoCaught)
    {
      numbers[i][0] = 4;
    }
    else if (!twoCaught && !threeCaught && !founde)
    {
      numbers[i][0] = 1;
    }
    twoCaught = false;
    twoCaughtS = false;
    threeCaught = false;
    founde = false;
    oldC = ' ';
  }

  for (int i = 1; i < numbers.size(); i++)
  {
    for (int j = 0; j < shuffled.size(); j++)
    {
      it = shuffled.begin();
      std::advance(it, j);
      if (numbers[i][0] > numbers[*it][0])
      {
        shuffled.insert(it, i);
        inserted = true;
        break;
      }
      else if (numbers[i][0] == numbers[*it][0])
      {
        if (numbers[i][1] > numbers[*it][1])
        {
          shuffled.insert(it, i);
          inserted = true;
          break;
        }
        else if (numbers[i][1] == numbers[*it][1])
        {
          if (numbers[i][2] > numbers[*it][2])
          {
            shuffled.insert(it, i);
            inserted = true;
            break;
          }
          else if (numbers[i][2] == numbers[*it][2])
          {
            if (numbers[i][3] > numbers[*it][3])
            {
              shuffled.insert(it, i);
              inserted = true;
              break;
            }
            else if (numbers[i][3] == numbers[*it][3])
            {
              if (numbers[i][4] > numbers[*it][4])
              {
                shuffled.insert(it, i);
                inserted = true;
                break;
              }
              else if (numbers[i][4] == numbers[*it][4])
              {
                if (numbers[i][5] > numbers[*it][5])
                {
                  shuffled.insert(it, i);
                  inserted = true;
                  break;
                }
              }
            }
          }
        }
      }
    }
    if (!inserted)
    {
      shuffled.push_back(i);
    }
    inserted = false;
  }

  int sizze = input.size();
  it = shuffled.begin();

  for (std::list<int>::iterator i = shuffled.begin(); i != shuffled.end(); i++)
  {
    answer += numbers[*i][6] * sizze;
    sizze--;
  }

  std::cout << std::format("Your total winnings are {}", answer) << std::endl;
}

int main()
{
  Day7Part1();
  return 0;
}