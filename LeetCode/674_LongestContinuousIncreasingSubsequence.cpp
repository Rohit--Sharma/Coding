#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findLengthOfLCIS(vector<int>& nums)
{
    if (nums.size() == 0)
        return 0;

    int res = 1, prev = 1;

    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] > nums[i - 1]) {
            res++;
        }
        else {
            prev = max(prev, res);
            res = 1;
        }
    }
    return max(prev, res);
}

int main()
{
    vector<int> input {1, 3, 5, 4, 7};
    cout << findLengthOfLCIS(input) << endl;

    input = vector<int> {2, 2, 2, 2, 2};
    cout << findLengthOfLCIS(input) << endl;

    input = vector<int> {2, 1, 2, 6, 4, 3, 5};
    cout << findLengthOfLCIS(input) << endl;

    input = vector<int> {2, 1, 2, 6, 4, 3, 5, 7, 8};
    cout << findLengthOfLCIS(input) << endl;
    return 0;
}