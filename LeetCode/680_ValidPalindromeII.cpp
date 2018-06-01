#include <iostream>
#include <string>
using namespace std;

int validPalindrome(string s)
{
    if (s.empty())
        return -1;
    int l = 0, r = s.size() - 1;
    while (l <= r) {
        if (s[l] != s[r])
            return l;
        l++;
        r--;
    }
    return -1;
}

// Returns if a string can be made a palindrome with at most one change
bool validAlmostPalindrome(string s)
{
    int palVioIndex = validPalindrome(s);
    if (palVioIndex == -1)
        return true;
    string lDel = s.substr(0, palVioIndex) + s.substr(palVioIndex + 1, s.size() - palVioIndex - 1);
    string rDel = s.substr(0, s.size() - palVioIndex - 1) + s.substr(s.size() - palVioIndex, palVioIndex);
    return validPalindrome(lDel) == -1 || validPalindrome(rDel) == -1;
}

int main()
{
    string inp;
    while (true) {
        cin >> inp;
        cout << validAlmostPalindrome(inp) << endl;
    }
    return 0;
}