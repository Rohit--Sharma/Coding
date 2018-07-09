#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>

using namespace std;

bool wordBreak(string s, vector<string>& wordDict)
{
    vector<bool> result(s.size() + 1, false);
    result[0] = true;

    /// DP 1
    // for (int i = 1; i <= s.size(); i++)
    //     for (string word : wordDict)
    //         if (word.size() <= i)
    //             if (result[i - word.size()])
    //                 if (s.substr(i - word.size(), word.size()) == word) {
    //                     result[i] = true;
    //                     break;
    //                 }

    /// DP 2
    set<string> mySet;
    for (string word : wordDict)
        mySet.insert(word);
    for(int i = 1; i <= s.size(); i++)
        for(int j = 0; j < i; j++)
            if(result[j] && mySet.find(s.substr(j, i - j)) != mySet.end()) {
                result[i] = true;
                break;
            }
    
    // for (bool res : result)
    //     cout << res << " ";
    // cout << endl;

    return result[s.size()];
}

int main()
{
    string inStr = "leezcode"; //"leetsuckscodeand";
    vector<string> inWordDict {"code", "leet", "sucks", "anderson", "and"};

    cout << wordBreak(inStr, inWordDict) << endl;

    return 0;
}