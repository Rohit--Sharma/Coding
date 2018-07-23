#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n_rows = matrix.size(), n_cols = matrix.size() == 0 ? 0 : matrix[0].size();
        int i = 0, j = n_cols - 1;
        while (i < n_rows && j >= 0) {
            if (matrix[i][j] == target)
                return true;
            else if (matrix[i][j] < target)
                i++;
            else if (matrix[i][j] > target)
                j--;
        }
        return false;
    }
};

int main()
{
    vector<vector<int>> input;
    input = vector<vector<int>> {
        {1,   4,  7, 11, 15},
        {2,   5,  8, 12, 19},
        {3,   6,  9, 16, 22},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}
    };
    cout << Solution().searchMatrix(input, 5) << endl;
    cout << Solution().searchMatrix(input, 20) << endl;

    return 0;
}