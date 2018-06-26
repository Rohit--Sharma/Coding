#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/// Solvable in O(n) using a very complex Manacher's algorithm

/// DP approach Attempt 1 TLE O(n^2)
string longestPalindromeTLE(string s)
{
    // dp vector to store if s[i..j] is a substring or not
    vector<vector<bool>> isSubstring(s.size(), vector<bool>(s.size(), false));

    int size = 1;
    while (size <= s.size()) {
        // cout << "Size: " << size << endl;
        for (int i = 0; i < s.size(); i++) {
            for (int j = i; j < s.size(); j++) {
                if (j - i + 1 == size) {
                    if (i == j) {
                        isSubstring[i][j] = true;
                    }
                    else if (j == i + 1) {
                        isSubstring[i][j] = s[i] == s[j];
                    }
                    else {
                        isSubstring[i][j] = isSubstring[i + 1][j - 1] && s[i] == s[j];
                    }
                    // cout << "(" << i << ", " << j << "): " << isSubstring[i][i] << endl;
                }
            }
        }
        size++;
    }

    int maxSubstrSize = -1;
    string longPalin;
    for (int i = 0; i < s.size(); i++) {
        for (int j = i; j < s.size(); j++) {
            // cout << isSubstring[i][j] << " ";
            if (isSubstring[i][j] && j - i + 1 > maxSubstrSize) {
                maxSubstrSize = j - i + 1;
                longPalin = s.substr(i, j - i + 1);
            }
        }
        // cout << endl;
    }

    return longPalin;
}

/// DP approach
/// Same algorithm as above but efficient implementation. Accepted O(n^2)
string longestPalindromeDP(string s)
{
    int len = s.size();

    // dp vector to store if s[i..j] is a substring or not
    vector<vector<bool>> isSubstring(len, vector<bool>(len, false));

    int longestPalinStart = 0, maxLen = 1;

    for (int i = 0; i < len; i++)
        isSubstring[i][i] = true;
    
    for (int i = 0; i < len - 1; i++)
        if (s[i] == s[i + 1]) {
            isSubstring[i][i + 1] = true;
            longestPalinStart = i;
            maxLen = 2;
        }

    for (int size = 3; size <= len; size++) {
        for (int i = 0; i < len - size + 1; i++) {
            int j = i + size - 1;
            if (isSubstring[i + 1][j - 1] && s[i] == s[j]) {
                isSubstring[i][j] = true;
                longestPalinStart = i;
                maxLen = size;
            }
        }
    }

    return s.substr(longestPalinStart, maxLen);
}

int expandAroundCenter(string s, int left, int right)
{
    int L = left, R = right;
    while (L >= 0 && R < s.size() && s[L] == s[R]) {
        L--;
        R++;
    }
    return R - L - 1;
}

/// O(1) space complexity algorithm
string longestPalindrome(string s)
{
    int start = 0, end = 0;
    for (int i = 0; i < s.size(); i++) {
        int len1 = expandAroundCenter(s, i, i);     // odd length palindromes
        int len2 = expandAroundCenter(s, i, i + 1); // even length palindromes
        // cout << i << " " << len1 << " " << len2 << endl;
        int len = max(len1, len2);
        if (len > end - start) {
            start = i - (len - 1) / 2;
            end = i + len / 2;
            // cout << "S: " << start << " E: " << end << endl;
        }
    }
    return s.substr(start, end - start + 1);
}

int main()
{
    string input;
    cin >> input;
    cout << longestPalindrome(input) << endl;
    return 0;
}