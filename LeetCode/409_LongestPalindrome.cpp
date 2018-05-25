#include <cstdio>
#include <string>
#include <map>
#include <vector>

using namespace std;

int longestPalindrome(string s) {
    map<char, int> charCounts;
    for (char ch : s)
        if (charCounts.find(ch) == charCounts.end())
            charCounts[ch] = 1;
        else
            charCounts[ch]++;

    int result = 0, maxOddCount = -1;
    vector<int> oddCharCounts;
    for (map<char, int>::iterator it = charCounts.begin(); it != charCounts.end(); it++) {
        if ((it->second % 2) == 0)
            result += it->second;
        else if((it->second % 2) != 0) {
            oddCharCounts.push_back(it->second);
            if (it->second > maxOddCount)
                maxOddCount = it->second;
        }
    }

    bool maxOddCharFound = false;
    for (int num : oddCharCounts)
        if (num == maxOddCount && !maxOddCharFound) {
            maxOddCharFound = true;
            result += num;
        } 
        else
            result += num - 1;
    return result;
}

int main()
{
    vector<string> inputs {"aa", "aA", "aaA", "aaAb", "aaab", "abcab", "aaabbbbb", "aaabbb"};   // 2, 1, 3, 3, 3, 5, 7, 5
    for (string input : inputs)
        printf("%d ", longestPalindrome(input));
    printf("\n");
    return 0;
}