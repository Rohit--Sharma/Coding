#include <cstdio>
#include <vector>

using namespace std;

void moveZeroes(vector<int>& nums)
{
    for (int lastNonZeroIndex = 0, currIndex = 0; currIndex < nums.size(); currIndex++) {
        if (nums.at(currIndex) != 0) {
            int temp = nums[currIndex];
            nums[currIndex] = nums[lastNonZeroIndex];
            nums[lastNonZeroIndex++] = temp;
        }
    }
}