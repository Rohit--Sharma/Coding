#include <iostream>
#include <vector>

using namespace std;

bool isToeplitzMatrix(vector<vector<int>>& matrix)
{
    int n_rows = matrix.size(), n_cols = matrix[0].size();

    int sr, sc;
    bool flag = true;

    for (sr = n_rows - 1, sc = 0; sr < n_rows && sc < n_cols; ) {
        int diagVal = matrix[sr][sc];
        int cur_r = sr, cur_c = sc;
        while (cur_r < n_rows && cur_c < n_cols) {
            if (matrix[cur_r][cur_c] != diagVal)
                return false;
            cur_r++; cur_c++;
        }
        if (sr != 0)
            sr--;
        if (sr == 0 && flag)
            flag = false;
        else if (sr == 0)
            sc++;
    }

    return true;
}

int main()
{
    vector<vector<int>> input {
        // {1, 2, 3, 4},
        // {5, 1, 2, 3},
        // {9, 5, 1, 2}

        {1, 2},
        {2, 2}
    };
    cout << isToeplitzMatrix(input) << endl;
    return 0;
}