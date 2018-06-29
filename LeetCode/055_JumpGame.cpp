#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

/// Time Complexity: O(2^n)
class SolutionTLE {
public:
    bool canJump(vector<int>& nums) {
        int start = 0;

        return canJumpTo(nums, start);
    }
private:
    bool canJumpTo(vector<int> nums, int index) {
        if (index == nums.size() - 1)
            return true;
        if (nums[index] == 0)
            return false;

        bool maxJump = false;
        for (int i = 1; i <= nums[index] && i < nums.size(); i++) {
            maxJump |= canJumpTo(nums, index + i);
        }
        return maxJump;
    }
};

/// Time Complexity: O(n^2)
///   Performs better than above but gives TLE for some more cases
///   Performance can be slightly improved if Bottom Up DP is implemented as there will be no recursion
class SolutionDPTopDown {
public:
    bool canJump(vector<int>& nums) {
        int start = 0;

        for (int i = 0; i < nums.size() - 1; i++) {
            seen.push_back(Index::UNKNOWN);
        }
        seen.push_back(Index::GOOD);    // last position of seen is Good trivially

        return canJumpFrom(nums, start);
    }

private:
    enum Index {
        GOOD, BAD, UNKNOWN
    };

    vector<Index> seen;

    bool canJumpFrom(vector<int> nums, int index) {
        if (seen[index] != Index::UNKNOWN)
            return seen[index] == Index::GOOD ? true : false;
        
        int furthestJump = min(index + nums[index], (int)nums.size() - 1);
        for (int nextPos = index + 1; nextPos <= furthestJump; nextPos++) {
            if (canJumpFrom(nums, nextPos)) {
                seen[nextPos] = Index::GOOD;
                return true;
            }
        }

        return false;
    }
};

/// O(n) Greedy algorithm. To understand why this works, see the working of bottom up DO approach
class Solution
{
public:
    bool canJump(vector<int>& nums) {
        int lastPos = nums.size() - 1;
        for (int i = nums.size() - 1; i >= 0; i--)
            if (i + nums[i] >= lastPos)
                lastPos = i;
        return lastPos == 0;
    }    
};

int main()
{
    vector<int> input {0, 1, 1, 1, 1};
    cout << Solution().canJump(input) << endl;

    input = vector<int> {2,3,1,1,4};
    cout << Solution().canJump(input) << endl;

    input = vector<int> {3,2,1,0,4};
    cout << Solution().canJump(input) << endl;

    input = vector<int> {3,2,2,0,4};
    cout << Solution().canJump(input) << endl;

    input = vector<int> {2, 5, 0, 0};
    cout << Solution().canJump(input) << endl;

    input = vector<int> {8,2,4,4,4,9,5,2,5,8,8,0,8,6,9,1,1,6,3,5,1,2,6,6,0,4,8,6,0,3,2,8,7,6,5,1,7,0,3,4,8,3,5,9,0,4,0,1,0,5,9,2,0,7,0,2,1,0,8,2,5,1,2,3,9,7,4,7,0,0,1,8,5,6,7,5,1,9,9,3,5,0,7,5};
    // cout << "Size: " << input.size() << endl;
    cout << Solution().canJump(input) << endl;

    input = vector<int> {2,0,6,9,8,4,5,0,8,9,1,2,9,6,8,8,0,6,3,1,2,2,1,2,6,5,3,1,2,2,6,4,2,4,3,0,0,0,3,8,2,4,0,1,2,0,1,4,6,5,8,0,7,9,3,4,6,6,5,8,9,3,4,3,7,0,4,9,0,9,8,4,3,0,7,7,1,9,1,9,4,9,0,1,9,5,7,7,1,5,8,2,8,2,6,8,2,2,7,5,1,7,9,6};
    cout << "Size: " << input.size() << endl;
    cout << Solution().canJump(input) << endl;

    return 0;
}