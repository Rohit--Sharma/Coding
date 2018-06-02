#include <iostream>
#include <string>
using namespace std;

/// Time complexity: O(n(n+m))
///    Space complexity: O(n+m)
int repeatedStringMatch(string A, string B)
{
    int q = 1;
    string S = A;
    while (S.size() < B.size()) {
        S += A;
        q++;
    }
    if (S.find(B) != string::npos)
        return q;
    if ((S + A).find(B) != string::npos)
        return q + 1;
    return -1;
}