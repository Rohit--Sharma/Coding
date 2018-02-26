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

int n, k;
string names[1005];
int groups[105];

bool debug = false;

void precompute()
{
	
}

void read()
{
	cin >> n >> k;
	assert(n <= 1000); assert(k <= 1000);
	
	for (unsigned int i = 0; i < n; i += 1) {
		cin >> names[i];
	}
}

void preprocess()
{
	memset(groups, 0, sizeof groups);
	
}

void solve()
{
	if (debug) {
		cout << "Inside solve" << endl;
	}
	for (unsigned int i = 0; i < n; i += 1) {
		groups[names[i].size()]++;
	}
	
	if (debug) {
		cout << "Groups: ";
		for (unsigned int i = 0; i < 105; i += 1) {
			cout << groups[i] << " ";
		}
		putchar('\n');
	}
	
	int nGroups = 0;
	for (unsigned int i = 0; i < 105; i += 1) {
		nGroups += groups[i]/k;
	}
	if (nGroups == n/k) {
		cout << "Possible" << endl;
	} else {
		cout << "Not possible" << endl;
	}
}

int main (int argc, char const* argv[])
{
	precompute();
	short t;
	cin >> t;
	assert(t <= 50);
	while (t--) {
		read();
		preprocess();
		solve();
	}
	return 0;
}
