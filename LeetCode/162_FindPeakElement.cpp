#include <iostream>
#include <vector>

using namespace std;

/// Similar to Binary Search
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if (nums.size() == 1)
            return 0;
        if (nums[0] > nums[1])
            return 0;
        if (nums[nums.size() - 1] > nums.size() - 2)
            return nums.size() - 1;
        
        return findPeak(nums, 0, nums.size() - 1);
    }

private:
    int findPeak(vector<int> nums, int l, int r) {
        if (l == r)
            return l;
        int mid = (l + r) / 2;
        if (nums[mid] > nums[mid + 1])
            return findPeak(nums, l, mid);
        return findPeak(nums, mid + 1, r);
    }
};

int main()
{
    vector<int> input;

    input = vector<int> {1, 2, 3, 1};
    cout << Solution().findPeakElement(input) << endl;

    input = vector<int> {1, 2, 1, 3, 5, 6, 4};
    cout << Solution().findPeakElement(input) << endl;

    input = vector<int> {1};
    cout << Solution().findPeakElement(input) << endl;

    input = vector<int> {3, 4, 3, 2, 1};
    cout << Solution().findPeakElement(input) << endl;

    return 0;
}