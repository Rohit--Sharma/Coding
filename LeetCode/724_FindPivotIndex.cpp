#include <iostream>
#include <vector>

using namespace std;

int pivotIndex(vector<int>& nums)
{
    if (nums.size() <= 1)
        return nums.size() - 1;

    vector<int> sumLeft(nums.size()), sumRight(nums.size());

    sumRight[nums.size() - 1] = nums[nums.size() - 1];
    sumLeft[0] = nums[0];
    for (int i = nums.size() - 2; i > -1; i--)
        sumRight[i] = sumRight[i + 1] + nums[i];

    if (sumRight[0] == sumLeft[0])
        return 0;

    for (int i = 1; i < nums.size(); i++) {
        sumLeft[i] = sumLeft[i - 1] + nums[i];
        if (sumRight[i] == sumLeft[i])
            return i;
    }

    return -1;
}

int main()
{
    vector<int> input {1, 2, 3};
    cout << pivotIndex(input) << endl;
    return 0;
}