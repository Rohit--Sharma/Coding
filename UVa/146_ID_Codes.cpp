#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

int main (int argc, char const* argv[])
{
	char input[52], hash[2] = "#";
	int strLength;
	
	cin >> input;
	
	while (strcmp(input, hash) != 0) {
		strLength = strlen(input);
		if (next_permutation(input, input + strLength)) {
			cout << input << endl;
		} else {
			cout << "No Successor" << endl;
		}
		cin >> input;
	}
	
	return 0;
}
