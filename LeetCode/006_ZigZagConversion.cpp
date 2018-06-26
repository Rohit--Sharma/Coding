#include <iostream>
#include <string>

using namespace std;

string convert(string s, int numRows)
{
    if (numRows == 1)
        return s;
    string result;
    int nR = numRows, currPos = 0;
    while (nR) {
        if (nR == numRows || nR == 1) {
            int index = currPos;
            while (index < s.size()) {
                result.append(s, index, 1);
                index += (numRows - 1) * 2;
            }
        }
        else {
            int index = currPos;
            while (index < s.size()) {
                result.append(s, index, 1);
                index += (nR - 1) * 2;
                if (index < s.size())
                    result.append(s, index, 1);
                index += (numRows - nR) * 2;
            }
        }
        currPos++;
        nR--;
    }
    return result;
}

int main()
{
    string input;
    cin >> input;
    int numRows;
    cin >> numRows;
    cout << convert(input, numRows) << endl;
    return 0;
}