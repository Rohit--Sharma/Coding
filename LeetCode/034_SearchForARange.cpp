#include <iostream>
#include <vector>

using namespace std;

// Simple implementation of binary search
vector<int> searchRange(vector<int>& nums, int target)
{
    vector<int> result;

    int l = 0, r = nums.size() - 1;
    while (l <= r) {
        // cout << l << " " << r << endl;
        int mid = l + (r - l) / 2;
        if (nums[mid] == target && ((mid - 1 < 0) || mid - 1 >= 0 && nums[mid - 1] != target)) {
            result.push_back(mid);
            break;
        }
        else if (nums[mid] >= target) {
            r = mid - 1;
        }
        else if (nums[mid] < target) {
            l = mid + 1;
        }
    }

    l = 0, r = nums.size() - 1;
    while (l <= r) {
        // cout << l << " " << r << endl;
        int mid = l + (r - l) / 2;
        if (nums[mid] == target && ((mid + 1 >= nums.size()) || mid + 1 < nums.size() && nums[mid + 1] != target)) {
            result.push_back(mid);
            break;
        }
        else if (nums[mid] <= target) {
            l = mid + 1;
        }
        else if (nums[mid] > target) {
            r = mid - 1;
        }
    }

    if (result.size() == 0) {
        result.push_back(-1), result.push_back(-1);
    }

    return result;
}

int main()
{
    vector<int> input {5,7,7,8,10};
    int tgt = 10;
    
    auto res = searchRange(input, tgt);
    for (int index : res) 
        cout << index << " ";
    cout << endl;

    return 0;
}