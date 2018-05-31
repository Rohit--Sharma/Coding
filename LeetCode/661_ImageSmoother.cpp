#include <vector>
#include <cstdio>
#include <iostream>

using namespace std;

vector<vector<int>> imageSmoother(vector<vector<int>>& M)
{
    auto res = M;
    for (int i = 0; i < M.size(); i++)
        for (int j = 0; j < M[i].size(); j++)
            res[i][j] = 0;
    
    for (int i = 0; i < M.size(); i++)
        for (int j = 0; j < M[i].size(); j++) {
            int count = 0;
            for (int nr = i - 1; nr <= i + 1; nr++)
                for (int nc = j - 1; nc <= j + 1; nc++)
                    if (0 <= nr && nr < M.size() && 0 <= nc && nc < M[i].size()) {
                        res[i][j] += M[nr][nc];
                        count++;
                    }
            res[i][j] /= count;
        }
    return res;
}

int main()
{

    return 0;
}