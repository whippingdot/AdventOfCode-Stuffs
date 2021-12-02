#include "../aoc.h"

// void Day1Part1()
// {
//   int answer;
//   vector<string> input = read_file("aoc/day-1/input.txt");
//   auto start = std::chrono::steady_clock::now();

//   cout << "bruh\n";

//   auto end = std::chrono::steady_clock::now();
//   cout << "Total time taken of part 1: " << std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() << "ns" << endl;
// }

int main()
{
  vector<string> input = read_file("input.txt"); // Changed from aoc/day-1/input.txt to input.txt
  int answer = 0;
  int prev_line = 0;

  for (string &line : input)
  {
    int line_n = stoi(line);

    if (line_n > prev_line)
    {
      answer++;
    }

    prev_line = line_n;
  }
  answer--;

  cout << "The answer is " << answer << endl;
}