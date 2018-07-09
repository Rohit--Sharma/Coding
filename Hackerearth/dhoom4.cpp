//#include <bits/stdc++.h>
#include <iostream>
#include <assert.h>
#include <string.h>
#include <queue>

using namespace std;

int key, lck;
int n;
int a[1003];
int val[100005];

bool debug = false;

void precompute()
{
	
}

void read()
{
	cin >> key >> lck >> n;
	assert(n <= 1000);
	for (unsigned int i = 0; i < n; i += 1) {
		cin >> a[i];
		assert(a[i] <= 100000);
	}
}

void preprocess()
{
	memset(val, -1, sizeof(val));	// Mem set of -1 can be done, else any other value leads to error co -1(8 bits): 11111111(base-2)
	val[key] = 0;
	
	if (debug) {
		cout << "Inside preprocess: " << sizeof val << endl;
		for (unsigned int i = 0; i < n; i += 1) {
			cout << val[i] << " ";
		}
		cout << endl;
	}
}

void solve()
{
	if (debug) {
		cout << "Inside solve: " << 1LL << endl;
	}
	queue<int> q;
	q.push(key);
	while (!q.empty()) {
		int f = q.front();
		q.pop();
		for (unsigned int i = 0; i < n; i += 1) {
			int nw = (1LL * f * a[i]) % 100000;
			if (val[nw] == -1) {
				val[nw] = 1 + val[f];
				q.push(nw);
			}
			if (nw == lck) {
				goto result;
			}
		}
	}
	result:
	cout << val[lck] << endl;
}

int main (int argc, char const* argv[])
{
	precompute();
	read();
	preprocess();
	solve();
	return 0;
}
