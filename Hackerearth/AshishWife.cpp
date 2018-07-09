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

int n, x;
set<LL> price;

void precompute()
{
	
}

void read()
{
	cin >> n >> x;
	assert(n <= 13000); assert(x <= 13000);
	
	LL temp;
	for (unsigned int i = 0; i < n; i += 1) {
		cin >> temp;
		price.insert(temp);
	}
}

void preprocess()
{
	price.clear();
}

void solve()
{
	if (price.size() < x) {
		cout << "Bad husband" << endl;
	} else if (price.size() == x) {
		cout << "Perfect husband" << endl;
	} else if (price.size() > x) {
		cout << "Lame husband" << endl;
	}
}

int main (int argc, char const* argv[])
{
	precompute();
	short t; cin >> t; assert(t <= 50);
	while (t--) {
		read();
		preprocess();
		solve();
	}
	return 0;
}
