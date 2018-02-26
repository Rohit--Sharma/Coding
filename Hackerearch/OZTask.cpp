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

string inp;

void precompute()
{
	
}

void read()
{
	cin >> inp;
}

void preprocess()
{
	
}

void solve()
{
	unsigned long long OsToLeft = 0, ZsToLeft = 0, nOs = 0, nZs = 0;
	
	for (unsigned long long i = 0; i < inp.size(); i += 1) {
		if (inp.at(i) == 'O') {
			nOs++;
			OsToLeft += nZs;
		}
		if (inp.at(i) == 'Z') {
			nZs++;
			ZsToLeft += nOs;
		}
	}
	
	(OsToLeft < ZsToLeft) ? (cout << OsToLeft << endl) : (cout << ZsToLeft << endl);
}

int main (int argc, char const* argv[])
{
	precompute();
	short t;
	cin >> t; 
	assert(t <= 10);
	while (t--) {
		read();
		preprocess();
		solve();
	}
	return 0;
}
