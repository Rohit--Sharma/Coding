#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool minimum(int a, int b)
{
    return a > b;
}

/// Also solvable in single scan
int maximumProduct(vector<int>& nums)
{
    vector<int> maxHeap = nums, minHeap = nums;
    make_heap(maxHeap.begin(), maxHeap.end());
    make_heap(minHeap.begin(), minHeap.end(), minimum);

    int neg1, neg2, pos1, pos2, pos3;

    pos1 = maxHeap.front();
    pop_heap(maxHeap.begin(), maxHeap.end());
    maxHeap.pop_back();

    pos2 = maxHeap.front();
    pop_heap(maxHeap.begin(), maxHeap.end());
    maxHeap.pop_back();

    pos3 = maxHeap.front();
    pop_heap(maxHeap.begin(), maxHeap.end());
    maxHeap.pop_back();

    neg1 = minHeap.front();
    pop_heap(minHeap.begin(), minHeap.end(), minimum);
    minHeap.pop_back();

    neg2 = minHeap.front();
    pop_heap(minHeap.begin(), minHeap.end(), minimum);
    minHeap.pop_back();

    return max(neg1 * neg2 * pos1, pos1 * pos2 * pos3);
}

int main()
{
    vector<int> input {-9, -6, 20, 11, 13};

    cout << maximumProduct(input) << endl;

    return 0;
}