#include <cstdio>
#include <vector>

using namespace std;

vector<int> twoSum(vector<int>& numbers, int target)
{
    int left = 0, right = numbers.size() - 1;

    while (left < right) {
        int sum = numbers.at(left) + numbers.at(right);
        if (sum == target)
            return vector<int> {left + 1, right + 1};
        
        if (sum < target)
            left++;
        else
            right--;
    }
}