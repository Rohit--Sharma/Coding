#include <cstdio>
#include <vector>

using namespace std;

/// Can be done using Dynamic Programming also as we construct new row based on prev row
vector<vector<int>> generatePascalsTriangle(int numRows) 
{
    vector<vector<int>> result;
    if (numRows == 0)
        return result;
    

    vector<int> pascalRowsPrev;
    pascalRowsPrev.push_back(1);
    result.push_back(pascalRowsPrev);
    if (numRows == 1)
        return result;

    pascalRowsPrev.push_back(1);
    result.push_back(pascalRowsPrev);
    if (numRows == 2)
        return result;
    
    for (int j = 2; j < numRows; j++) {
        vector<int> newPascalRow;
        newPascalRow.push_back(1);
        for (int i = 0; i < pascalRowsPrev.size() - 1; i++) {
            newPascalRow.push_back(pascalRowsPrev.at(i) + pascalRowsPrev.at(i + 1));
        }
        newPascalRow.push_back(1);
        result.push_back(newPascalRow);
        pascalRowsPrev = newPascalRow;
    }

    return result;
}

int main()
{

    return 0;
}