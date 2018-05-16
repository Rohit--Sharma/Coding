#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int maxRobProfitDP(vector<int> nums, int lastIndex, vector<int>& profitMemo);

/// Time complexity: O(n), but gives TLE
int robDP(vector<int>& nums)
{
    if (nums.size() == 0)
        return 0;
    vector<int> profitMemo(nums.size(), 0);

    return maxRobProfitDP(nums, nums.size() - 1, profitMemo);
}

/// Linear scan algo, time complexity: O(n)
/// Algo: robMax and skipMax denotes max profit gained if we rob this house or not.
///       If we rob this house, we must have skipped adjacent prev house.
///       If we skip this house, then max profit = max from rob prev house or skip prev house.
int rob(vector<int>& nums)
{
    int robMax = 0, skipMax = 0;
    for (int n : nums) {
        int robMaxPrev = robMax, skipMaxPrev = skipMax;
        robMax = skipMaxPrev + n;                   // rob this house
        skipMax = max(robMaxPrev, skipMaxPrev);     // skip this house
    }
    return max(robMax, skipMax);
}

// *************** Utility functions *************** //
int maxRobProfitDP(vector<int> nums, int lastIndex, vector<int>& profitMemo)
{
    if (lastIndex == 0) {
        profitMemo[lastIndex] = nums.at(0);
        return nums.at(0);
    }
    if (lastIndex == 1) {
        profitMemo[lastIndex] = max(nums.at(0), nums.at(1));
        return profitMemo[lastIndex];
    }

    if (profitMemo[lastIndex - 1] == 0)
        profitMemo[lastIndex - 1] = maxRobProfitDP(nums, lastIndex - 1, profitMemo);
    if (profitMemo[lastIndex - 2] == 0)
        profitMemo[lastIndex - 2] = maxRobProfitDP(nums, lastIndex - 2, profitMemo);
    return max(profitMemo[lastIndex - 1], profitMemo[lastIndex - 2] + nums.at(lastIndex));
}

int main()
{
    vector<int> input = vector<int> {2, 1, 1, 2};

    printf("%d\n", rob(input));

    input = vector<int> {1, 2, 3, 1};

    printf("%d\n", rob(input));

    input = vector<int> {2, 7, 9, 3, 1};

    printf("%d\n", rob(input));
    return 0;
}