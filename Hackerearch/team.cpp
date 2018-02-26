#include <iostream>
#include <bitset>
#include <assert.h>

using namespace std;

bool debug = false;

int main (int argc, char const* argv[])
{
	short n, m;
	size_t max = 0;
	cin >> n >> m;
	assert(n <= 500);
	assert(m <= 500);
	
	int noTeams[501] = {0};
	bitset<500> knowsTopic[500], temp;
	
	for (unsigned int i = 0; i < n; i += 1) {
		cin >> knowsTopic[i];
	}
	
	for (unsigned int i = 0; i < n - 1; i += 1) {
		for (unsigned int j = i + 1; j < n; j += 1) {
			temp = knowsTopic[i] | knowsTopic[j];
			if (debug) cout << "Setbits count: " << temp.count() << endl;
			if (temp.count() >= max) {
				if (debug) cout << "Inside" << endl;
				max = temp.count();
				noTeams[max]++;
			}
		}
	}
	
	cout << max << endl << noTeams[max];
	
	return 0;
}
