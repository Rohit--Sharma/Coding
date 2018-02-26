#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

unsigned long long merge(vector<int> &arr, int l1, int r1, int l2, int r2)
{
	vector<int> sorted;
	unsigned long long noInv = 0;
	
	int i, j;
	
	for (i = l1, j = l2; i <= r1 && j <= r2;) {
		if (arr[i] <= arr[j]) {
			sorted.push_back(arr[i++]);
		} else if (arr[i] > arr[j]) {
			sorted.push_back(arr[j++]);
			noInv += (r1 - i + 1);
		}
	}
	if (i > r1) {
		while (j <= r2) {
			sorted.push_back(arr[j++]);
		}
	}
	if (j > r2) {
		while (i <= r1) {
			sorted.push_back(arr[i++]);
		}
	}
	for (int i = l1, j = 0; i < l1 + sorted.size(); i += 1) {
		arr[i] = sorted[j++];
	}
	
	return noInv;
}

unsigned long long mergeSort(vector<int> &arr, int strt, int end)
{
	if (strt == end) {
		return 0;
	}
	
	int left1 = strt, right1 = (strt + end)/2, left2 = (strt + end)/2 + 1, right2 = end;
	
	unsigned long long inversionsLeft = mergeSort(arr, left1, right1);
	unsigned long long inversionsRight = mergeSort(arr, left2, right2);
	
	unsigned long long inversionsCombine = merge(arr, left1, right1, left2, right2);
	
	return inversionsCombine + inversionsLeft + inversionsRight;
}

unsigned long long minSwaps(vector<int> &a)
{
	return mergeSort(a, 0, a.size() - 1);
}

int main (int argc, char const* argv[])
{
	int n, temp;
	cin >> n;
	
	vector<int> a;
	
	while (n != 0) {
		a.resize(0);
	
		for (int i = 0; i < n; i += 1) {
			cin >> temp;
			a.push_back(temp);
		}
		
		cout << minSwaps(a) << endl;
		
		cin >> n;
	}
}
