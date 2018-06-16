#include <iostream>
#include <string>

using namespace std;

int countBinarySubstrings(string s)
{
    int result = 0;
    int n_zeros = 0, n_ones = 0;
    bool currentZero = s[0] == '0' ? true : false;
    for (char ch : s) {
        switch (ch) {
            case '0':
                if (currentZero)
                    n_zeros++;
                else
                    n_zeros = 1;
                if (n_zeros <= n_ones)
                    result++;
                currentZero = true;
                break;
            case '1':
                if (!currentZero)
                    n_ones++;
                else
                    n_ones = 1;
                if (n_ones <= n_zeros)
                    result++;
                currentZero = false;
                break;
        }
    }
    return result;
}

int main()
{
    cout << countBinarySubstrings("00110011") << endl;  // Output: 6

    cout << countBinarySubstrings("10101") << endl;     // Output: 4

    cout << countBinarySubstrings("1100") << endl;    // Output: 3

    return 0;
}