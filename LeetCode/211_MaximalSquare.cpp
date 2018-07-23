#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/// Time complexity: O((mn)^2)
class Solution_BruteForce {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int maxSqSize = 0, currSqSize;

        int n_rows = matrix.size(), n_cols = matrix.size() > 0 ? matrix[0].size() : 0;
        for (int i = 0; i < n_rows; i++) {
            for (int j = 0; j < n_cols; j++) {
                if (matrix[i][j] == '1') {
                    currSqSize = 1;
                    int cur_r = i + 1, cur_c = j + 1;
                    bool isSquare = true;
                    while (cur_r < n_rows && cur_c < n_cols && isSquare) {
                        for (int p = i; p <= cur_r; p++) {
                            if (matrix[p][cur_c] == '0') {
                                isSquare = false;
                                break;
                            }
                        }
                        for (int q = j; q <= cur_c; q++) {
                            if (matrix[cur_r][q] == '0') {
                                isSquare = false;
                                break;
                            }
                        }
                        if (isSquare)
                            currSqSize++;
                        cur_r++;
                        cur_c++;
                    }
                    maxSqSize = max(maxSqSize, currSqSize);
                }
            }
        }

        return maxSqSize * maxSqSize;
    }
};

/// Dinamic Programming solution. Complexity: O(mn)
class Solution_DP {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int maxSqSize = 0;
        int n_rows = matrix.size(), n_cols = matrix.size() > 0 ? matrix[0].size() : 0;
        vector<vector<int>> dp (n_rows + 1, vector<int>(n_cols + 1, 0));        // dp[i][j] indicates the max size of square with (i, j) as the bottom right corner
        for (int i = 1; i <= n_rows; i++) {
            for (int j = 1; j <= n_cols; j++) {
                if (matrix[i - 1][j - 1] == '1') {
                    dp[i][j] = min(dp[i - 1][j], min(dp[i - 1][j - 1], dp[i][j - 1])) + 1;
                    maxSqSize = max(maxSqSize, dp[i][j]);
                }
            }
        }
        return maxSqSize * maxSqSize;
    }
};

int main()
{
    vector<vector<char>> input {
        {'1', '0', '1', '0', '0'},
        {'1', '0', '1', '1', '1'},
        {'1', '1', '1', '1', '1'},
        {'1', '0', '0', '1', '0'}
    };
    cout << Solution_DP().maximalSquare(input) << endl;
    
    return 0;
}