#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

void nextPermutation(vector<int>& nums)
{
    int i;
    for (i = nums.size() - 1; i >= 0; i--) {
        if (i - 1 >= 0 && nums[i - 1] >= nums[i]) {
            continue;
        } else {
            break;
        }
    }

    if (i - 1 >= 0) {
        int noToSwap = nums[i - 1], nextGreatest = INT_MAX, nextGreatestIndex = i;
        for (int j = i; j < nums.size(); j++) {
            if (nums[j] > noToSwap) {
                nextGreatest = min(nextGreatest, noToSwap);
                nextGreatestIndex = j;
            }
        }
    
        int temp = nums[i - 1];
        nums[i - 1] = nums[nextGreatestIndex];
        nums[nextGreatestIndex] = temp;
    }

    // Improvement: Since the numbers from index i to the end are in decreasing order already, in order to sort then in ascending order,
    //    we could have just reversed the numbers to make it run in O(n) instead of O(nlg n)
    sort(nums.begin() + i, nums.end());
}

int main()
{
    vector<int> input {7,3,5,1,2,8,9,6,4};
    nextPermutation(input);
    for (int x : input)
        cout << x << " ";
    cout << endl;

    input = vector<int> {1, 2, 3, 4};
    nextPermutation(input);
    for (int x : input)
        cout << x << " ";
    cout << endl;

    input = vector<int> {4, 3, 2, 1};
    nextPermutation(input);
    for (int x : input)
        cout << x << " ";
    cout << endl;

    input = vector<int> {1, 1, 5};
    nextPermutation(input);
    for (int x : input)
        cout << x << " ";
    cout << endl;

    input = vector<int> {1, 3, 2};
    nextPermutation(input);
    for (int x : input)
        cout << x << " ";
    cout << endl;

    input = vector<int> {8, 6, 9, 7, 4};
    nextPermutation(input);
    for (int x : input)
        cout << x << " ";
    cout << endl;

    return 0;
}