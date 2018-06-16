#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int findShortestSubArray(vector<int>& nums)
{
    map<int, int> left, right, count;
    int degree = 0;

    for (int i = 0; i < nums.size(); i++) {
        int x = nums[i];
        if (left.find(x) == left.end())
            left[x] = i;
        right[x] = i;
        if (count.find(x) == count.end())
            count[x] = 1;
        else
            count[x]++;
        degree = max(degree, count[x]);
    }
    
    int ans = nums.size();
    for (auto cnt = count.begin(); cnt != count.end(); cnt++)
        if (cnt->second == degree)
            ans = min(ans, right[cnt->first] - left[cnt->first] + 1);
    return ans;
}

int main()
{
    vector<int> input {2, 1, 3, 1, 4, 2};
    cout << findShortestSubArray(input) << endl;
    return 0;
}