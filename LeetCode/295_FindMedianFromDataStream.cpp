#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <stack>
#include <map>
#include <unordered_map>
#include <set>
#include <queue>
#include <list>
#include <algorithm>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode (int x) : val(x), left(NULL), right(NULL) {}
};

// Similar to insertion sort, keep the vector sorted and insert a value in 
//  its correct position using Binary search. 
// Time complexity: O(n)
class MedianFinder {
public:
    /** initialize your data structure here. */
    vector<int> store;	// re-sizeable container

    MedianFinder() {}

    void addNum(int num) {
        if (store.empty())
            store.push_back(num);
        else
            store.insert(lower_bound(store.begin(), store.end(), num), num);    // binary search and insertion combined
    }

    double findMedian() {
        int n = store.size();
        return n & 1 ? store[n / 2] : (store[n / 2 - 1] + store[n / 2]) * 0.5;
    }
};

// Using two heaps: max heap to store first half and min heap to store second half of elements
//   Median can be found by just accessing the top of the heaps
// Time complexity: O(log n)
class MedianFinderII {
public:
    MedianFinderII() {}

    void addNum(int num) {
        lo.push(num);                                    // Add to max heap

        hi.push(lo.top());                               // balancing step
        lo.pop();

        if (hi.size() > lo.size()) {                     // maintain size property
            lo.push(hi.top());
            hi.pop();
        }
    }

    double findMedian() {
        return lo.size() > hi.size() ? lo.top() : (lo.top() + hi.top()) * 0.5;
    }

private:
    /** initialize your data structure here. */
    priority_queue<int> lo;                               // max heap for first half elements
    priority_queue<int, vector<int>, greater<int>> hi;    // min heap for second half elements
};

int main() {
    MedianFinder* obj = new MedianFinder();
    obj->addNum(1);
    obj->addNum(2);
    cout << obj->findMedian() << endl;
    obj->addNum(3);
    cout << obj->findMedian() << endl;

    return 0;
}
