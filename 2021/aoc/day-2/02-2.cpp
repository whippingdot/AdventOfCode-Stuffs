#include "../aoc.h"

void Day2Part1()
{
  vector<string> input = read_file("input.txt");
  int answer = 0;
  int int_char = 0;
  int horizontal_poz = 0;
  int aim = 0;
  int depth = 0;

  char character = ' ';
  char string_int_char = ' ';

  vector<char> characters = vector<char>();

  for (string &line : input)
  {
    characters.clear();
    for (char &character : line)
    {
      characters.push_back(character);
    }

    character = characters[0];
    if (character == 'f')
    {
      string_int_char = characters[characters.size() - 1];
      int_char = string_int_char - '0';
      horizontal_poz += int_char;
      depth += aim * int_char;
    }
    else if (character == 'd')
    {
      string_int_char = characters[characters.size() - 1];
      int_char = string_int_char - '0';
      aim += int_char;
    }
    else if (character == 'u')
    {
      string_int_char = characters[characters.size() - 1];
      int_char = string_int_char - '0';
      aim -= int_char;
    }
  }
  answer = horizontal_poz * depth;

  cout << "The answer is " << answer << endl;
}

int main()
{
  Day2Part1();
  return 0;
}