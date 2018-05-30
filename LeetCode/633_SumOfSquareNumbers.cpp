#include <cstdio>
#include <cmath>
#include <iostream>

using namespace std;

bool judgeSquareSum(int c)
{
    for (long i = 0; i * i <= c; i++) {
        double sq_rt = sqrt(c - i * i);
        if (sq_rt == (int)sq_rt)
            return true;
    }
    return false;
}

/// Another interesting solution similar to Binary Search logic
bool judgeSquareSumBin(int c)
{
    int start = 0, end = (int) sqrt(c);
    while (start <= end) {
        long sum = start * start + end * end;
        if (sum == c)
            return true;
        else if (sum >= c)
            end--;
        else
            start++;
    }
    return false;
}

int main()
{
    int in;
    cin >> in;
    cout << judgeSquareSumBin(in) << endl;
    return 0;
}