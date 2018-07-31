#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/// Complexity: O(m + n)
class Solution_Bruteforce {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        auto mergedArray = mergeSortedArrays(nums1, nums2);
        int sz = mergedArray.size();
        if (sz % 2 == 0)
            return (mergedArray[sz / 2 - 1] + mergedArray[sz / 2]) / 2.0;
        else
            return mergedArray[sz / 2];
    }

private:
    vector<int> mergeSortedArrays(vector<int> nums1, vector<int> nums2) {
        vector<int> res;
        int nums1_ptr = 0, nums2_ptr = 0;
        for (int i = 0; i < nums1.size() + nums2.size(); i++) {
            if (nums1_ptr < nums1.size() && nums2_ptr < nums2.size()) {
                if (nums1[nums1_ptr] < nums2[nums2_ptr]) {
                    res.push_back(nums1[nums1_ptr++]);
                }
                else {
                    res.push_back(nums2[nums2_ptr++]);
                }
            }
            else {
                break;
            }
        }
        if (nums1_ptr < nums1.size()) {
            for (int i = nums1_ptr; i < nums1.size(); i++) 
                res.push_back(nums1[i]);
        }
        if (nums2_ptr < nums2.size())
            for (int i = nums2_ptr; i < nums2.size(); i++)
                res.push_back(nums2[i]);
        return res;
    }
};

/// Complexity: O(lg(m + n))
class Solution_BinarySearch {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        if (m == 0)
            return medianArray(nums2);
        if (n == 0)
            return medianArray(nums1);
        
        if (m > n) {
            vector<int> temp = nums1, nums1 = nums2, nums2 = temp;
            int tmp = m, m = n, n = tmp;
        }
        int imin = 0, imax = m;
        
        while (imin <= imax) {
            int i = (imin + imax) / 2, j = (m + n + 1) / 2 - i;     // Ensure i + j = (m - i) + (n - j) to have len(left) = len(right)
            if ((j == 0 || i == m || nums2[j - 1] <= nums1[i]) && (i == 0 || j == n || nums1[i - 1] <= nums2[j])) {
                int maxLeft = 0;
                if (i == 0)
                    maxLeft = nums2[j - 1];
                else if (j == 0)
                    maxLeft = nums1[i - 1];
                else
                    maxLeft = max(nums1[i - 1], nums2[j - 1]);

                if ((m + n) % 2 == 0) {
                    int minRight = 0;
                    if (i == m)
                        minRight = nums2[j];
                    else if (j == n)
                        minRight = nums1[i];
                    else
                        minRight = min(nums1[i], nums2[j]);
                    return (maxLeft + minRight) / 2.0;
                }
                else
                    return maxLeft;
            }
            else if (i < imax && nums2[j - 1] > nums1[i]) {
                imin++;
            }
            else if (i > imin && nums1[i - 1] > nums2[j]) {
                imax--;
            }
        }
        return 0.0;
    }

private:
    double medianArray(vector<int> nums) {
        if (nums.size() == 0)
            return 0;
        return (nums.size() % 2 == 0) ? (nums[nums.size() / 2 - 1] + nums[nums.size() / 2]) / 2.0 : nums[nums.size() / 2];
    }
};

int main()
{
    vector<int> input1, input2;

    input1 = vector<int> {1, 3};
    input2 = vector<int> {2};
    cout << Solution_BinarySearch().findMedianSortedArrays(input1, input2) << endl;

    input1 = vector<int> {1, 2};
    input2 = vector<int> {3, 4};
    cout << Solution_BinarySearch().findMedianSortedArrays(input1, input2) << endl;

    input1 = vector<int> {2};
    input2 = vector<int> {};
    cout << Solution_BinarySearch().findMedianSortedArrays(input1, input2) << endl;

    return 0;
}