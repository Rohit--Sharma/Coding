#include <iostream>
#include <string.h>

using namespace std;

int noSwaps(short size, short *array)
{
	int ans = 0;
	
	for (short k = size - 1; k > 0; k -= 1) {
		for (short i = 0; i < k; i += 1) {
			if (array[i] > array[i+1]) {
				array[i] ^= array[i+1] ^= array[i] ^= array[i+1];
				ans++;
			}
		}
	}
	
	return ans;
}

int main (int argc, char const* argv[])
{
	int t; cin >> t;
	short length, carriages[51];
	
	while (t--) {
		cin >> length;
		bzero(carriages, sizeof(carriages));
		
		for (short i = 0; i < length; i += 1) {
			cin >> carriages[i];
		}
		
		cout << "Optimal train swapping takes " << noSwaps(length, carriages) << " swaps." << endl;
	}
	
	return 0;
}
