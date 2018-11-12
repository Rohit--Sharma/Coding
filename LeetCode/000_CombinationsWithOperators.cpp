#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <stack>
#include <map>
#include <set>
#include <queue>
#include <list>
#include <algorithm>

using namespace std;

vector<string> combinations(string input, int target) {
	// cout << "Calling with (" << input << ", " << target << ")\n";
	if (input.size() == 0)
	{
		vector<string> combs;
		if (target == 0)
		{
			combs.push_back("");
		}
		return combs;
	}
	int entire_number = stoi(input);
	/*if(entire_number == target) {
		vector<string> combs = new ArrayList<>();
		combs.push_back(input);
		return combs;
  	}*/
	vector<string> result;
	int first_number = 0;
	for (int i = 0; i < input.size(); i++)
	{
		first_number = 10 * first_number + (input[i] - '0');
		// first_number + combinations
		vector<string> possibleCombinationsForAddition = combinations(input.substr(i + 1, input.size() - i - 1), target - first_number);
		// combine with first_number
		string f_number = input.substr(0, i + 1); // (0,...i) substring
		if (possibleCombinationsForAddition.size() > 0)
		{
			for (int j = 0; j < possibleCombinationsForAddition.size(); j++)
			{
				result.push_back(to_string(first_number) + " + " + possibleCombinationsForAddition.at(j));
			}
		}
		// first_number - combinations
		vector<string> possibleCombinationsForSubtraction = combinations(input.substr(i + 1, input.size() - i - 1), first_number - target);
		if (possibleCombinationsForSubtraction.size() > 0)
		{
			for (int j = 0; j < possibleCombinationsForSubtraction.size(); j++)
			{
				result.push_back(to_string(first_number) + " - (" + possibleCombinationsForSubtraction.at(j) + ")");
			}
		}
	}
	return result;
}

int main() {
	vector<string> res;

	res = combinations("123", 15);
	for (string str: res) {
		cout << str << endl;
	}
	cout << endl;

	res = combinations("123456789", 100);
	for (string str: res) {
		cout << str << endl;
	}
	cout << endl;

    return 0;
}
