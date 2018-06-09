#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

// Exception handling slows down the code a lot
int area(int r, int c, vector<vector<int>> &grid)
{
    try {
        if (grid.at(r).at(c) == 1) {
            grid[r][c] = 0;

            return 1 + 
                area(r - 1, c, grid) + 
                area(r, c - 1, grid) + 
                area(r + 1, c, grid) + 
                area(r, c + 1, grid);
        }
    }
    catch (out_of_range) { }
    return 0;
}

int maxAreaOfIsland(vector<vector<int>> &grid)
{
    int maxArea = 0;
    for (int i = 0; i < grid.size(); i++)
        for (int j = 0; j < grid[i].size(); j++)
            if (grid[i][j] == 1)
                maxArea = max(maxArea, area(i, j, grid));
    return maxArea;
}

// Accepted but beats only 2% submissions
// Remove exception handling for better speed
int maxAreaOfIslandIterative(vector<vector<int>> &grid)
{
    int n_rows = grid.size(), n_cols = 0;
    try {
        n_cols = grid.at(0).size();
    }
    catch (out_of_range) { }
    vector<vector<bool>> seen(n_rows, vector<bool>(n_cols, false));
    vector<int> move_r {1, -1, 0, 0};
    vector<int> move_c {0, 0, 1, -1};

    int maxArea = 0;
    for (int i = 0; i < n_rows; i++) {
        for (int j = 0; j < n_cols; j++) {
            if (grid[i][j] == 1 && !seen[i][j]) {
                int shape = 0;
                stack<pair<int, int>> myStack;
                myStack.push(make_pair(i, j));
                seen[i][j] = true;
                while (!myStack.empty()) {
                    pair<int, int> node = myStack.top(); myStack.pop();
                    int r = node.first, c = node.second;
                    shape++;
                    for (int k = 0; k < 4; k++) {
                        int nr = r + move_r[k];
                        int nc = c + move_c[k];
                        try {
                            if (grid.at(nr).at(nc) == 1 && !seen.at(nr).at(nc)) {
                                myStack.push(make_pair(nr, nc));
                                seen[nr][nc] = true;
                            }
                        }
                        catch (out_of_range) { }
                    }
                }
                maxArea = max(maxArea, shape);
            }
        }
    }
    return maxArea;
}

int main()
{
    vector<vector<int>> input {
        // Case 1:
        {0,0,1,0,0,0,0,1,0,0,0,0,0},
        {0,0,0,0,0,0,0,1,1,1,0,0,0},
        {0,1,1,0,1,0,0,0,0,0,0,0,0},
        {0,1,0,0,1,1,0,0,1,0,1,0,0},
        {0,1,0,0,1,1,0,0,1,1,1,0,0},
        {0,0,0,0,0,0,0,0,0,0,1,0,0},
        {0,0,0,0,0,0,0,1,1,1,0,0,0},
        {0,0,0,0,0,0,0,1,1,0,0,0,0}

        // Case 2:
        // {1,1,0,0,0},
        // {1,1,1,0,0},
        // {0,0,1,1,1},
        // {0,0,0,1,1}

        // Case 3:
        // {0,0,0,0,0,0,0,0}

        // Case 4:
        // {1,1},
        // {1,0}
    };
    cout << maxAreaOfIsland(input) << endl;
    return 0;
}