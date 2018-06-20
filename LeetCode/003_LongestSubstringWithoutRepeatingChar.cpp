#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

int lengthOfLongestSubstring(string s)
{
    map<char, int> charPos;
    int lenLongSubstr = 0, subStrStart = 0;

    for (int i = 0; i < s.size(); i++) {
        if (charPos.find(s[i]) != charPos.end())
            subStrStart = max(subStrStart, charPos[s[i]] + 1);
        lenLongSubstr = max(lenLongSubstr, i - subStrStart + 1);
        charPos[s[i]] = i;
    }

    return lenLongSubstr;
}

int main()
{
    string input;
    cin >> input;
    cout << lengthOfLongestSubstring(input) << endl;
    return 0;
}