#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <stack>
#include <map>
#include <queue>
#include <list>
#include <algorithm>

using namespace std;

class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        map<string, int> bannedWords;
        for (string bannedWord : banned) {
            bannedWords[bannedWord] = 1;
        }

        vector<string> words;
        for (int i = 0; i < paragraph.size(); i++) {
            string word;
            while (paragraph[i] != ' ' && paragraph[i] != '!' && paragraph[i] != '\'' && paragraph[i] != '?' && paragraph[i] != ',' && paragraph[i] != ';' && paragraph[i] != '.') {
                word += tolower(paragraph[i]);
                i++;
            }
            if (word.size() > 0 && bannedWords.find(word) == bannedWords.end())
                words.push_back(word);
        }

        map<string, int> myMap;

        for (string word : words) {
            if (myMap.find(word) == myMap.end()) {
                myMap[word] = 1;
            }
            else {
                myMap[word]++;
            }
        }

        int max = -1;
        string mostCommon;
        for (auto start = myMap.begin(); start != myMap.end(); start++) {
            if (start->second > max) {
                max = start->second;
                mostCommon = start->first;
            }
        }
        return mostCommon;
    }
};

int main()
{
    string input_para;
    vector<string> input_banned;

    input_para = "Bob hit a ball, the hit BALL flew far after it was hit.";
    input_banned = vector<string> {"hit"};
    cout << Solution().mostCommonWord(input_para, input_banned) << endl;

    return 0;
}