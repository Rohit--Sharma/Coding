#include <cstdio>
#include <string>
#include <vector>

using namespace std;

string longestCommonPrefix_(string str1, string str2)
{
    int i = 0;
    string result = "";
    while (i < str1.length() && i < str2.length() && str1.at(i) == str2.at(i)) {
        result.append(1, str1.at(i++));
    }
    return result;
}

string longestCommonPrefix(vector<string>& strs) {
    if (strs.size() > 1) {
        string result = longestCommonPrefix_(strs[0], strs[1]);
        for (int i = 2; i < strs.size(); i++) {
            result = longestCommonPrefix_(result, strs[i]);
        }
        return result;
    }
    else if (strs.size() == 1)
        return strs[0];
    else
        return "";
}

int main()
{

    return 0;
}