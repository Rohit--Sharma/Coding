#include <cstdio>
#include <vector>
#include <map>

using namespace std;

/// Hashtable implementation:
///   Time complexity: O(n), Space complexity: O(n)
int majorityElement(vector<int>& nums)
{
    map<int, int> m;

    for (int i = 0; i < nums.size(); i++) {
        if (m.find(nums.at(i)) == m.end())
            m[nums.at(i)] = 1;
        else
            m[nums.at(i)]++;
    }

    map<int, int>::iterator it;
    for (it = m.begin(); it != m.end(); it++) {
        if (it->second > nums.size() / 2)
            return it->second;
    }
}

/// Divide and Conquer approach:
///    Time complexity: O(nlg n), Space complexity: O(lg n)
int majorityElementDivideAndConquer(vector<int>& nums)
{
    return majorityElementRec(nums, 0, nums.size() - 1);
}

/// Boyer-Moore Voting Algorithm:
///    Time complexity: O(n), Space Complexity: O(1)
int majorityElementBoyerMoore(vector<int>& nums)
{
    int candidate, count = 0;

    for (int i = 0; i < nums.size(); i++) {
        if (count == 0)
            candidate = nums.at(i);
        
        candidate == nums.at(i) ? count++ : count--;
    }

    return candidate;
}


//*************** Utility functions ***************//

/// Utility function for Divide and Conquer approach
int majorityElementRec(vector<int>& nums, int lo, int hi)
{
    // If there's only one element, return that
    if (lo == hi)
        return nums.at(lo);
    
    // Recurse on the left and right sides of this slice
    int mid = (hi - lo) / 2 + lo;
    int left = majorityElementRec(nums, lo, mid);
    int right = majorityElementRec(nums, mid + 1, hi);

    // Return the majority element if both left and right halves have the same value
    if (left == right)
        return left;
    
    int leftCount = countInRange(nums, left, lo, hi);
    int rightCount = countInRange(nums, right, lo, hi);

    return leftCount > rightCount ? left : right;
}

int countInRange(vector<int> nums, int num, int lo, int hi)
{
    int count = 0;
    for (int i = lo; i <= hi; i++)
        if (nums.at(i) == num)
            count++;
    return count;
}