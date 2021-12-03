#include "../aoc.h"

void Day3Part1()
{
	vector<string> input = read_file("input.txt");
  
	vector<int> nums = vector<int>();

	for (string str : input) {
		nums.push_back(stoi(str, 0, 2));
	}

	int bit = 0;

	char gammabits[12];

	char epsilonbits[12];

	for (int i = 11; i >= 0; i--) {
		int set = 0;
		int unset = 0;

		for (int num : nums) {
			if (num & (1 << i))
				set++;
			else
				unset++;
		}

		gammabits[11 - i] = set > unset ? '1' : '0';

		epsilonbits[11 - i] = set < unset ? '1' : '0';
	}

	// Converting bits to a string for stoi
	string str = "";

	for (int i = 0; i < 12; i++) {
		str += gammabits[i];
	}

	int gamma = stoi(str, 0, 2);

	str = "";

	for (int i = 0; i < 12; i++) {
		str += epsilonbits[i];
	}

	int epsilon = stoi(str, 0, 2);

	cout << "Gamma: "  << gamma << "\n";
	
	cout << "Epsilon: " << epsilon << "\n";
}

int main()
{
  Day3Part1();
  return 0;
}