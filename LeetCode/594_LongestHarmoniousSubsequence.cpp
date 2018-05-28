#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

/// Time complexity: O(n), Space complexity: O(n)
int findLHS(vector<int>& nums)
{
    map<int, int> myMap;
    int res = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (myMap.find(nums[i]) == myMap.end())
            myMap[nums[i]] = 1;
        else
            myMap[nums[i]]++;

        if (myMap.find(nums[i] - 1) != myMap.end())
            res = max(res, myMap[nums[i] - 1] + myMap[nums[i]]);
        if (myMap.find(nums[i] + 1) != myMap.end())
            res = max(res, myMap[nums[i] + 1] + myMap[nums[i]]);
    }
    return res;
}

int main()
{
    vector<int> input {1, 3, 2, 2, 5, 2, 3, 7};
    cout << findLHS(input) << endl;

    input = vector<int> {1, 2, 3, 4};
    cout << findLHS(input) << endl;

    input = vector<int> {1};
    cout << findLHS(input) << endl;

    input = vector<int> {};
    cout << findLHS(input) << endl;
    return 0;
}