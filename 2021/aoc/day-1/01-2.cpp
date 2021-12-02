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
  int extra_prev_line = 0;
  int prev_line = 0;
  int prev_prev_line = 0;
  int prev_3_line = 0;

  for (string &line : input)
  {
    int line_n = stoi(line);
    extra_prev_line = line_n;

    line_n += prev_line + prev_prev_line;

    if (line_n > prev_3_line)
    {
      answer++;
    }

    prev_3_line = line_n;
    prev_prev_line = prev_line;
    prev_line = extra_prev_line;
  }
  answer -= 3;

  cout << "The answer is " << answer << endl;
}