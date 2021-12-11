#include "../../aoc.h"

vector<int> Filter(vector<int> nums, int place, bool co2 = false) {
	vector<int> filtered = vector<int>();

	int set = 0;
	int unset = 0;

	place = 11 - place;

	for (int num : nums) {
		if (num & (1 << place))
			set++;
		else
			unset++;
	}

	bool check = set >= unset;

	if (co2)
		check = set < unset;

	for (int num : nums) {
		if (num & (1 << place) && check)
			filtered.push_back(num);
		else if (! (num & (1 << place)) && ! check)
			filtered.push_back(num);
	}

	return filtered;
}

void Day3Part2()
{
	vector<string> input = read_file("input.txt");
  
	vector<int> nums = vector<int>();

	for (string str : input) {
		nums.push_back(stoi(str, 0, 2));
	}

	vector<int> full = nums;

	int oxygenrating;

	int co2rating;

	for (int i = 0; i < 12; i++) {
		nums = Filter(nums, i);

		if (nums.size() == 1) {
			oxygenrating = nums[0];

			break;
		}
	}

	nums = full;

	for (int i = 0; i < 12; i++) {
		nums = Filter(nums, i, true);

		if (nums.size() == 1) {
			co2rating = nums[0];

			break;
		}
	}

	cout << "Oxygen rating: " << oxygenrating << "\n";
	
	cout << "CO2 rating: " << co2rating << "\n";
}

int main()
{
  Day3Part2();
  return 0;
}