#include <iostream>
#include <assert.h>
#include <vector>
#include <algorithm>

using namespace std;

typedef unsigned long long LL;

typedef struct {
	LL ind;
	LL t;
	LL l;
} cookingTime;

bool comparator(cookingTime a, cookingTime b)
{
	return a.t < b.t;
}

bool minHeapComparator(cookingTime a, cookingTime b)
{
	return a.l > b.l;
}

bool debug = true;

int main (int argc, char const* argv[])
{
	LL n, waitingTime = 0, currentTime = 0, timeToJump = 0;
	cin >> n; assert(n <= 100000);
	
	vector<cookingTime> cookingTimes;
	
	for (LL i = 0; i < n; i += 1) {
		cookingTime temp;
		temp.ind = i+1;
		cin >> temp.t; assert(temp.t <= 1000000000);
		cin >> temp.l; assert(temp.l <= 1000000000);
		
		cookingTimes.push_back(temp);
	}
	
	sort(cookingTimes.begin(), cookingTimes.end(), comparator);
	
	if (debug) {
		cout << endl << "Checking vector after sorting:" << endl;
		for (LL i = 0; i < n; i += 1) {
			cout << cookingTimes[i].ind << ") " << cookingTimes[i].t << " " << cookingTimes[i].l << endl;
		}
		cout << endl;
	}
	
	vector<cookingTime> minHeap;
	minHeap.push_back(cookingTimes[0]); 
	currentTime = cookingTimes[0].t;
	push_heap(minHeap.begin(), minHeap.end(), minHeapComparator);	// Actually not needed to heapify because minheap has only 1 element
	
	LL index = 1;
	
	while (!minHeap.empty()) {
		cookingTime shortestJob = minHeap.front();
		pop_heap (minHeap.begin(), minHeap.end(), minHeapComparator); 
		minHeap.pop_back();
		
		if (debug) {
			cout << "Current time: " << currentTime << endl <<
				"Shortest job picked: " << shortestJob.ind << ") " << shortestJob.t << " " << shortestJob.l << endl;
		}
		currentTime += shortestJob.l;
		waitingTime += (currentTime - shortestJob.t);
		
		LL nPicked = 0;
		for (; index < n; index += 1) {
			if (cookingTimes[index].t <= currentTime) {
				minHeap.push_back(cookingTimes[index]);
				push_heap(minHeap.begin(), minHeap.end(), minHeapComparator);
				nPicked++;
			} else if (nPicked == 0) {
				minHeap.push_back(cookingTimes[index]);
				push_heap(minHeap.begin(), minHeap.end(), minHeapComparator);
				index++;
				break;
			} else
				break;
		}
	}
	
	cout << waitingTime / n << endl;
	
	if (debug) {
		LL maxLL = -1;
		cout << "Max LL: " << maxLL << endl;
	}
	
	
	return 0;
}
