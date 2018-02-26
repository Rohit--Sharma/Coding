#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stdlib.h>
#include <string.h>

using namespace std;

bool comp(short a, short b)
{
	if (a > b)
		return true;
	return false;
}

void printAns(vector<short> boysHeights, vector<short> girlsHeights)
{
	if (boysHeights.size() > girlsHeights.size()) {
		cout << "NO" << endl;
		return;
	}
	
	unsigned int i = 0, j = 0;
	for (; i < boysHeights.size() && j < girlsHeights.size(); i += 1, j += 1) {
		if (boysHeights[i] <= girlsHeights[j]) {
			i--;
		}
	}
	if (i == boysHeights.size()) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}
}

int main (int argc, char const* argv[])
{
	short t; cin >> t;
	int m, n;
	vector<short> mHeights, nHeights;
	
	while (t--) {
		cin >> m >> n;
		mHeights.resize(0);
		nHeights.resize(0);
		short input;
		
		for (int i = 0; i < m; i += 1) {
			cin >> input;
			mHeights.push_back(input);
		}
		for (int i = 0; i < n; i += 1) {
			cin >> input;
			nHeights.push_back(input);
		}
		
		stable_sort(mHeights.begin(), mHeights.end(), comp);
		stable_sort(nHeights.begin(), nHeights.end(), comp);
		
		printAns(mHeights, nHeights);
	}
	return 0;
}
