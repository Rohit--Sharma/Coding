#include <cstdio>
#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;

/// A nice algorithm using stack
///   Time Complexity: O(n)
///   Space Complexity: O(n)
int findUnsortedSubarray(vector<int>& nums)
{
    stack<int> lStack, rStack;
    int l = nums.size(), r = 0;
    for (int i = 0; i < nums.size(); i++) {
        while (!lStack.empty() && nums[lStack.top()] > nums[i]) {
            int top = lStack.top();
            l = min(l, top);
            lStack.pop();
        }
        lStack.push(i);
    }
    for (int i = nums.size() - 1; i > -1; i--) {
        while (!rStack.empty() && nums[rStack.top()] < nums[i]) {
            int top = rStack.top();
            r = max(r, top);
            rStack.pop();
        }
        rStack.push(i);
    }
    return r - l > 0 ? r - l + 1 : 0;
}

/// A more efficient algorithm which doesn't use extra space
///    Time Complexity: O(n)
///    Space Complexity: O(1)
int findUnsortedSubarrayEfficient(vector<int>& nums)
{
    // Determine where the array sort goes wrong from left and right
    int minimum = INT_MAX, maximum = INT_MIN;
    bool flag = false;
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] < nums[i - 1])
            flag = true;
        if (flag)
            minimum = min(minimum, nums[i]);
    }
    flag = false;
    for (int i = nums.size() - 2; i > -1; i--) {
        if (nums[i] > nums[i + 1])
            flag = true;
        if (flag)
            maximum = max(maximum, nums[i]);
    }

    // Determine the correct position of minimum and maximum
    int l, r;
    for (l = 0; l < nums.size(); l++)
        if (minimum < nums[l])
            break;
    for (r = nums.size() - 1; r > -1; r--)
        if (maximum > nums[r])
            break;
    return r - l > 0 ? r - l + 1 : 0;
}

int main()
{
    vector<int> input {2, 6, 4, 8, 10, 9, 15};
    cout << findUnsortedSubarrayEfficient(input) << endl;
    return 0;
}