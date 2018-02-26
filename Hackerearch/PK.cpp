#include <bits/stdc++.h>

using namespace std;

#define MOD		1000000007
#define INF		(int)1e9
#define LINF	(long long)1e18
#define EPS		1e-9

typedef long long ll;
typedef unsigned long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
typedef pair<int, PII> TRI;
typedef vector<int> VI;
typedef vector<LL> VL;
typedef vector<ll> vl;
typedef vector<PII> VII;
typedef vector<TRI> VT;

bool alphabetFollow[26][26];
char c;
int len;
bool debug = true;

void precompute()
{
	short temp;
	for (unsigned int i = 0; i < 26; i += 1) {
		for (unsigned int j = 0; j < 26; j += 1) {
			cin >> temp;
			if (temp)
				alphabetFollow[i][j] = true;
			else	
				alphabetFollow[i][j] = false;
		}
	}
}

void read()
{
	cin >> c >> len;
	assert(2 <= len && len <= 100000000);
}

void preprocess()
{
	
}

void solve()
{
	vector<int> array[len];
	array[0].push_back(c - 97);
	for (unsigned int i = 1; i < len; i += 1) {
		if (debug)
			cout << "i: " << i << "\nVector: ";
		while (!array[i-1].empty()) {
			int last = array[i-1].back();
			if (debug) {
				cout << last << " ";
			}
			for (int k = 0; k < 26; k++) {
				if (alphabetFollow[k][last]) {
					array[i].push_back(k);
				}
			}
			array[i-1].pop_back();
		}
		if (debug)
			putchar('\n');
	}
	cout << array[len - 1].size() << endl;
}

int main (int argc, char const* argv[])
{
	precompute();
	if (debug) {
		cout << "Entering debug mode:" << endl << endl;
	}
	short t; cin >> t; assert(t <= 100);
	while (t--) {
		read();
		preprocess();
		solve();
	}
	return 0;
}
