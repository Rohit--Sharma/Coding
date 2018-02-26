#include <iostream>
#include <bitset>
#include <stdio.h>

using namespace std;

int main (int argc, char const* argv[])
{
	int n;
	bitset<32> input, answer;
	while (scanf("%d", &n) != EOF) {
		input = n;
		answer = 0;
		
		for (unsigned int i = 0; i < 8; i += 1) {
			if (input.test(i + 24)) {
				answer.set(i);
 			}
 			if (input.test(i + 16)) {
 				answer.set(i + 8);
 			}
 			if (input.test(i + 8)) {
 				answer.set(i + 16);
 			}
 			if (input.test(i)) {
 				answer.set(i + 24);
 			}
		}
		
		cout << n << " converts to " << (int)answer.to_ulong() << endl;
	}
	return 0;
}
