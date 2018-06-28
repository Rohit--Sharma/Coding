#include <iostream>
#include <vector>

using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix)
{
    vector<int> result;

    if (matrix.size() == 0)
        return result;
    
    vector<int> drxns_c {1, 0, -1, 0}, 
        drxns_r {0, 1, 0, -1};
    vector<vector<bool>> seen(matrix.size(), vector<bool>(matrix[0].size(), false));

    int dir = 0;
    int s_r = 0, s_c = 0;
    int size = matrix.size() * matrix[0].size();
    while (size--) {
        if (s_r >= 0 && s_r < matrix.size() && s_c >= 0 && s_c < matrix[0].size() && !seen[s_r][s_c]) {
            result.push_back(matrix[s_r][s_c]);
            seen[s_r][s_c] = true;
            s_r += drxns_r[dir];
            s_c += drxns_c[dir];
        }
        else {
            s_r -= drxns_r[dir];
            s_c -= drxns_c[dir];
            dir = (dir + 1) % 4;
            s_r += drxns_r[dir];
            s_c += drxns_c[dir];
            size++;
        }
    }

    return result;
}

int main()
{
    vector<vector<int>> input {
        // {1, 2, 3},
        // {4, 5, 6},
        // {7, 8, 9}

        // {1, 2, 3, 4},
        // {5, 6, 7, 8},
        // {9, 10, 11, 12}

        {1}
    };

    auto res = spiralOrder(input);

    for (int el : res)
        cout << el << " ";
    cout << endl;

    return 0;
}