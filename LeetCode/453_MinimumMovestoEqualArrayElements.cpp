#include <cstdio>
#include <vector>
#include <limits>
#include <iostream>

using namespace std;

/// Very inefficient, O(n^2)
class Solution {
public:
    int minMoves(vector<int>& nums) {
        int maxVal;
        int maxIndex;
        int result = 0;
        while (!allEqual(nums)) {
            maxVal = numeric_limits<int>::min();
            maxIndex = -1;
            // cout << "In main func: ";
            // for (int n : nums)
            //     cout << n << " ";
            // cout << endl;
            for (int i = 0; i < nums.size(); i++)
                if (nums[i] > maxVal) {
                    maxVal = nums[i];
                    maxIndex = i;
                }
            // cout << "Max index: " << maxIndex << endl;
            for (int i = 0; i < nums.size(); i++)
                if (i != maxIndex)
                    nums[i]++;
            // for (int n : nums)
            //     cout << n << " ";
            // cout << endl;
            result++;
        }
        return result;
    }
    
private:
    bool allEqual(vector<int> nums) {
        // cout << "In allEqual(): ";
        // for (int n : nums)
        //     cout << n << " ";
        // cout << endl;
        int temp = nums[0];
        for (int num : nums)
            if (num != temp)
                return false;
        return true;
    }
};

/// Efficient O(n) implementation
int minMoves(vector<int>& nums)
{
    int sum = 0, min = numeric_limits<int>::max();
    for (int n : nums) {
        sum += n;
        if (n < min)
            min = n;
    }
    return sum - nums.size() * min;
}

int main()
{
    vector<int> input {1, 2, 3};
    cout << Solution().minMoves(input) << endl;
    return 0;
}