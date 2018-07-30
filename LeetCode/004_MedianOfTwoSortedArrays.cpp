#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
    }
};

int main()
{
    vector<int> input1, input2;

    input1 = vector<int> {1, 3};
    input2 = vector<int> {2};
    cout << Solution().findMedianSortedArrays(input1, input2) << endl;

    input1 = vector<int> {1, 2};
    input2 = vector<int> {3, 4};
    cout << Solution().findMedianSortedArrays(input1, input2) << endl;

    return 0;
}