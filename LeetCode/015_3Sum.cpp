#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <stack>
#include <map>
#include <set>
#include <queue>
#include <list>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;

        sort(nums.begin(), nums.end());
        for (size_t i = 0; i < nums.size() - 2; i++) {
            if (i == 0 || (i > 0 && nums[i] != nums[i - 1])) {
                int sum_to_find = -nums[i];
                int lo = i + 1, hi = nums.size() - 1;
                while (lo < hi) {
                    int sum = nums[lo] + nums[hi];
                    if (sum == sum_to_find) {
                        result.push_back({nums[i], nums[lo], nums[hi]});
                        while (lo + 1 < nums.size() && nums[lo] == nums[lo + 1])
                            lo++;
                        while (hi > 0 && nums[hi] == nums[hi - 1])
                            hi--;
                        lo++;
                        hi--;
                    } 
                    else if (sum < sum_to_find) {
                        lo++;
                    }
                    else if (sum > sum_to_find) {
                        hi--;
                    }
                }
            }
        }

        return result;
    }
};

int main() {
    vector<int> input = {-1, 0, 1, 2, -1, -4};
    auto out = Solution().threeSum(input);
    for (auto vec : out) {
        cout << "[ ";
        for (int num : vec) {
            cout << num << " ";
        }
        cout << ']' << endl;
    }
    return 0;
}