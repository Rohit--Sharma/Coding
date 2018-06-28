#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs)
{
    map<string, vector<string>> str_to_analist;

    for (string str : strs) {
        string sorted = str;
        sort(sorted.begin(), sorted.end());
        if (str_to_analist.find(sorted) == str_to_analist.end()) {
            str_to_analist[sorted] = vector<string> {str};
        }
        else {
            str_to_analist[sorted].push_back(str);
        }
    }

    vector<vector<string>> result;
    for (auto analist = str_to_analist.begin(); analist != str_to_analist.end(); analist++) {
        result.push_back(analist->second);
    }

    return result;
}

int main()
{

    return 0;
}