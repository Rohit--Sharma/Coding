#include <iostream>
#include <map>
#include <stdio.h>

using namespace std;

int main (int argc, char const* argv[])
{
	int t, m, k, cost;	cin >> t;
	map<char, int> charCostTable;
	char ch, c;
	unsigned long long ans;
	
	while (t--) {
		charCostTable.clear();
		ans = 0;
		cin >> k;
		while (k--) {
			cin >> ch >> cost;
			charCostTable[ch] = cost;
		}
		cin >> m;
		getchar();
		while (m--) {
			while ((c = getchar()) != '\n') {
				if (charCostTable.find(c) != charCostTable.end()) {
					ans += charCostTable.find(c)->second;
				}
			}
		}
		
		printf("%.2lf$\n", ans / 100.0);
	}
	
	return 0;
}
