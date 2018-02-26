#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stdlib.h>
#include <string.h>

using namespace std;

typedef struct {
	char sequence[52];
	int noInversions;
} node;

void countInversions(vector<node> &seq)
{
	for (short i = 0; i < seq.size(); i += 1) {
		string dnaSeq = seq[i].sequence;
		int sum = 0;
		
		for (short j = 0; j < dnaSeq.size() - 1; j += 1) {
			for (short k = j + 1; k < dnaSeq.size(); k += 1) {
				if (dnaSeq[j] > dnaSeq[k]) {
					sum++;
				}
			}
		}
		
		seq[i].noInversions = sum;
	}
	return;
}

bool comp(node a, node b)
{
	if (a.noInversions < b.noInversions) {
		return true;
	}
	return false;
}

int main (int argc, char const* argv[])
{
	int t; cin >> t;
	short m, n;
	vector<node> sequences;
	bool printNewLine = false;
	
	while (t--) {
		cin >> m >> n;
		sequences.resize(0);
		string input;
		
		if (printNewLine) {
			cout << endl;
		}
		printNewLine = true;
		
		for (short i = 0; i < n; i += 1) {
			cin >> input;
			node *tmp = (node *)malloc(sizeof(node));
			strcpy(tmp->sequence, input.data());
			
			sequences.push_back(*tmp);
		}
		
		countInversions(sequences);
		
		stable_sort(sequences.begin(), sequences.end(), comp);
		
		for (short i = 0; i < sequences.size(); i += 1) {
			cout << sequences[i].sequence << endl;
		}
	}
	return 0;
}
