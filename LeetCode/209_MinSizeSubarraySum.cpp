#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

/// O(n^2) time complexity. Check every substring and return the min dist one
class Solution_BruteForce {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        
        vector<int> cumulativeSum;
        cumulativeSum.push_back(nums[0]);

        for (int i = 1; i < nums.size(); i++) {
            cumulativeSum.push_back(cumulativeSum[i - 1] + nums[i]);
        }

        int res = INT_MAX;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i; j < nums.size(); j++) {
                int sum = cumulativeSum[j] - cumulativeSum[i] + nums[i];
                if (sum >= s) {
                    res = min(res, j - i + 1);
                    break;
                }
            }
        }
        return res == INT_MAX ? 0 : res;
    }
};

/// O(nlg n) complexity. Instead of searching linearly in the above method, we use binary search
class Solution_BinarySearch {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int n = nums.size();
        if (n == 0)
            return 0;
        
        int ans = INT_MAX;
        vector<int> cumulativeSum(n + 1, 0);    // size = n + 1 for easier calc
        for (int i = 1; i <= n; i++)
            cumulativeSum[i] = cumulativeSum[i - 1] + nums[i - 1];
        for (int i = 1; i <= n; i++) {
            int to_find = s + cumulativeSum[i - 1];
            auto bound = lower_bound(cumulativeSum.begin(), cumulativeSum.end(), to_find);
            if (bound != cumulativeSum.end())
                ans = min(ans, (int)(bound - (cumulativeSum.begin() + i - 1)));
        }
        return ans == INT_MAX ? 0 : ans;
    }
};

int main()
{
    int s = 7;
    vector<int> input {2, 3, 1, 2, 4, 3};
    cout << Solution_BinarySearch().minSubArrayLen(s, input) << endl;
    return 0;
}