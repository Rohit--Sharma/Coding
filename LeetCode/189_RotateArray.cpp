#include <cstdio>
#include <vector>

using namespace std;

/// Time complexity: O(n), Space complexity: O(n)
void rotate(vector<int>& nums, int k)
{
    int length = nums.size();

    // concatenate the vector to itself
    for (int i = 0; i < length - (k % length); i++) {
        nums.push_back(nums.at(i));
    }

    nums = vector<int>(nums.begin() + length - (k % length), nums.end());
}

/// Time complexity: O(n), Space complexity: O(1)
///    Algo: to rotate k steps, first reverse, then reverse first k char, then reverse last n - k char
void rotateInPlace(vector<int>& nums, int k)
{
    k %= nums.size();
    reverse(nums, 0, nums.size() - 1);
    reverse(nums, 0, k - 1);
    reverse(nums, k, nums.size() - 1);
}

/// Utility function
void reverse(vector<int>& nums, int start, int end)
{
    while (start < end) {
        int temp = nums.at(start);
        nums[start] = nums[end];
        nums[end] = temp;
        start++; end--;
    }
}