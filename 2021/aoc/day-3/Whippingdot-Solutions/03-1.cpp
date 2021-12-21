#include "../../aoc.h"

void Day3Part1()
{
  vector<string> input = read_file("input.txt");
  int answer = 0;
  int zero_count = 0;
  int one_count = 0;
  int gamma = 0;
  int epsilon = 0;
  int counter = 0;

  string gamma_binary_value = "";
  string epsilon_binary_value = "";

  vector<char> line_vector = vector<char>();
  vector<char> gamma_but_vector = vector<char>();
  vector<char> epsilon_but_vector = vector<char>();

  for (int i = 0; i < 12; i++)
  {
    zero_count = 0;
    one_count = 0;
    for (string &line : input)
    {
      line_vector.clear();
      for (char &c : line)
      {
        line_vector.push_back(c);
      }

      if (line_vector[i] == '0')
      {
        zero_count++;
      }
      else if (line_vector[i] == '1')
      {
        one_count++;
      }
    }

    if (zero_count < one_count)
    {
      gamma_binary_value += "1";
    }
    else if (one_count < zero_count)
    {
      gamma_binary_value += "0";
    }
  }

  for (char &c : gamma_binary_value)
  {
    gamma_but_vector.push_back(c);
    c == '0' ? epsilon_binary_value += "1" : epsilon_binary_value += "0";
  }
  for (char &c : epsilon_binary_value)
  {
    epsilon_but_vector.push_back(c);
  }

  for (int x = 11; x >= 0; x--)
  {
    if (gamma_but_vector[x] == '1')
    {
      gamma += 1 * pow(2, counter);
    }
    else if (gamma_but_vector[x] == '0')
    {
      gamma += 0 * pow(2, counter);
    }

    if (epsilon_but_vector[x] == '1')
    {
      epsilon += 1 * pow(2, counter);
    }
    else if (epsilon_but_vector[x] == '0')
    {
      epsilon += 0 * pow(2, counter);
    }
    counter++;
  }

  answer = gamma * epsilon;

  cout << gamma_binary_value << endl;
  cout << epsilon_binary_value << endl;

  cout << "The answer is " << answer << endl;
}

int main()
{
  Day3Part1();
  return 0;
}