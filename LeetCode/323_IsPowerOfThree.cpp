#include <cstdio>
#include <cmath>
#include <iostream>

using namespace std;

bool isPowerOfThree(int n) {
    return n > 0 && 1162261467 % n == 0;
}

int main()
{
    int input;
    cin >> input;
    cout << isPowerOfThree(input) << endl;
    return 0;
}