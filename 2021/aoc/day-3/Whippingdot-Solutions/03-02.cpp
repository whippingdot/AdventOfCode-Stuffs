#include "../../aoc.h"

vector<string> removeIfLower(int i, char lowerNumber, vector<string> input)
{
  vector<string>::iterator iterator;
  vector<string> fakeInput = input;
  vector<char> characters = vector<char>();
  vector<int> remover = vector<int>();

  int funcCounter = 0;

  for (string &line : input)
  {
    characters.clear();
    for (char &c : line)
    {
      characters.push_back(c);
    }
    if (characters[i] == lowerNumber)
    {
      iterator = find(input.begin(), input.end(), line);
      remover.push_back((iterator - funcCounter) - input.begin());
    }
  }

  for (int x = 0; x < remover.size(); x++)
  {
    input.clear();
    for (int debugVar = 0; debugVar < fakeInput.size(); debugVar++)
    {
      if (fakeInput[debugVar] != fakeInput[remover[x]])
      {
        input.push_back(fakeInput[debugVar]);
      }
    }
    fakeInput = input;
    // input.erase(input.begin() - remover[x]); - Why is this not working
  }

  return input;
}

vector<string> removeIfGreater(int i, char greaterNumber, vector<string> input)
{
  vector<string>::iterator iterator;
  vector<string> fakeInput = input;
  vector<char> characters = vector<char>();
  vector<int> remover = vector<int>();

  int funcCounter = 0;

  for (string &line : input)
  {
    characters.clear();
    for (char &c : line)
    {
      characters.push_back(c);
    }
    if (characters[i] == greaterNumber)
    {
      iterator = find(input.begin(), input.end(), line);
      remover.push_back((iterator - funcCounter) - input.begin());
    }
  }

  for (int x = 0; x < remover.size(); x++)
  {
    input.clear();
    for (int debugVar = 0; debugVar < fakeInput.size(); debugVar++)
    {
      if (fakeInput[debugVar] != fakeInput[remover[x]])
      {
        input.push_back(fakeInput[debugVar]);
      }
    }
    fakeInput = input;
  }

  return input;
}

void Day3Part2()
{
  vector<string> input = read_file("input.txt");
  vector<string> o2_input = input;
  vector<string> co2_input = input;

  int answer = 0;
  int o2_zero_count = 0;
  int o2_one_count = 0;
  int co2_zero_count = 0;
  int co2_one_count = 0;
  int o2_rating = 0;
  int co2_rating = 0;
  int counter = 0;
  int co2_counter = 0;

  char greater = ' ';
  char lower = ' ';

  vector<char> char_vector = vector<char>();
  vector<char> o2_but_vector = vector<char>();
  vector<char> co2_but_vector = vector<char>();

  for (int i = 0; i < 12; i++)
  {
    o2_zero_count = 0;
    o2_one_count = 0;
    co2_zero_count = 0;
    co2_one_count = 0;
    for (string &line : o2_input)
    {
      char_vector.clear();
      for (char &c : line)
      {
        char_vector.push_back(c);
      }

      if (char_vector[i] == '0')
      {
        o2_zero_count++;
      }
      else if (char_vector[i] == '1')
      {
        o2_one_count++;
      }
    }

    if (o2_zero_count < o2_one_count)
    {
      lower = '0';
      o2_input = removeIfLower(i, lower, o2_input);
    }
    else if (o2_one_count < o2_zero_count)
    {
      lower = '1';
      o2_input = removeIfLower(i, lower, o2_input);
    }
    else if (o2_one_count == o2_zero_count)
    {
      lower = '0';
      o2_input = removeIfLower(i, lower, o2_input);
    }

    co2_counter = 0;
    for (string &line : co2_input)
    {
      char_vector.clear();
      for (char &c : line)
      {
        char_vector.push_back(c);
      }

      if (char_vector[i] == '0')
      {
        co2_zero_count++;
      }
      else if (char_vector[i] == '1')
      {
        co2_one_count++;
      }
      co2_counter++;
    }

    if (co2_counter != 1)
    {
      if (co2_zero_count < co2_one_count)
      {
        greater = '1';
        co2_input = removeIfGreater(i, greater, co2_input);
      }
      else if (co2_one_count < co2_zero_count)
      {
        greater = '0';
        co2_input = removeIfGreater(i, greater, co2_input);
      }
      else if (co2_one_count == co2_zero_count)
      {
        greater = '1';
        co2_input = removeIfGreater(i, greater, co2_input);
      }
    }
  }

  for (char &c : o2_input[0])
  {
    o2_but_vector.push_back(c);
  }
  for (char &c : co2_input[0])
  {
    co2_but_vector.push_back(c);
  }

  for (int x = 11; x >= 0; x--)
  {
    if (o2_but_vector[x] == '1')
    {
      o2_rating += 1 * pow(2, counter);
    }
    else if (o2_but_vector[x] == '0')
    {
      o2_rating += 0 * pow(2, counter);
    }

    if (co2_but_vector[x] == '1')
    {
      co2_rating += 1 * pow(2, counter);
    }
    else if (co2_but_vector[x] == '0')
    {
      co2_rating += 0 * pow(2, counter);
    }
    counter++;
  }

  cout << "Oxygen Rating: " << o2_rating << endl;
  cout << "Carbon Dioxide Rating: " << co2_rating << endl;

  answer = o2_rating * co2_rating;

  cout << "The answer is " << answer << endl;
}

int main()
{
  Day3Part2();
  return 0;
}