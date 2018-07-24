#include <iostream>
#include <vector>

using namespace std;

/// Time complexity: O(n^2). Accepted but very inefficient
class Solution_BruteForce {
public:
    int findDuplicate(vector<int>& nums) {
        if (nums.size() == 0)
            return -1;
        for (int i = 0; i < nums.size(); i++)
            for (int j = i + 1; j < nums.size(); j++)
                if (nums[i] == nums[j])
                    return nums[i];
    }
};

/// Floyd's Tortoise and Hare (Cycle Detection) Algorithm
///   Time complexity: O(n), Space complexity: O(1)
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        if (nums.size() == 0)
            return -1;
            
        // Find the intersection point of the two runners.
        int tortoise = nums[0];
        int hare = nums[0];
        do {
            tortoise = nums[tortoise];
            hare = nums[nums[hare]];
        } while (tortoise != hare);

        // Find the "entrance" to the cycle.
        int ptr1 = nums[0];
        int ptr2 = tortoise;
        while (ptr1 != ptr2) {
            ptr1 = nums[ptr1];
            ptr2 = nums[ptr2];
        }

        return ptr1;
    }
};

int main()
{

    return 0;
}