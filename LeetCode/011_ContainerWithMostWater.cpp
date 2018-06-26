#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/// BruteForce TLE O(n^2)
int maxAreaTLE(vector<int>& height)
{
    int result = 0;
    for (int i = 0; i < height.size() - 1; i++) {
        for (int j = i + 1; j < height.size(); j++) {
            int area = min(height[i], height[j]) * (j - i);
            result = max(area, result);
        }
    }
    return result;
}

/// An awesome O(n) single pass approach
int maxArea(vector<int>& height)
{
    int result = 0;
    int left = 0, right = height[height.size() - 1];
    while (right > left) {
        result = max(min(height[left], height[right]) * (right - left), result);
        if (height[left] > height[right])
            right--;
        else
            left++;
    }
    return result;
}

int main()
{
    vector<int> input {3, 1, 7, 5, 4};
    cout << maxArea(input) << endl;
    return 0;
}