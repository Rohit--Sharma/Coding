#include <cstdio>
#include <vector>

using namespace std;

int missingNumber(vector<int>& nums)
{
    int sum = 0;
    for (int n : nums)
        sum += n;
    
    int size = nums.size();
    return size * (size + 1) / 2 - sum;
}