#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <stack>
#include <map>
#include <set>
#include <queue>
#include <list>
#include <algorithm>

using namespace std;

class Solution {
public:
    string nextClosestTime(string time) {
        set<char> allowedChars;
        for (char timeChar : time)
            allowedChars.insert(timeChar);
        
        int timeInt = stoi(time.substr(0, 2)) * 60 + stoi(time.substr(3, 2));
        
        for (int i = 0; i < 24 * 60; i++) {
            timeInt++;
            // cout << timeInt << endl;
            if (timeInt == 24 * 60)
                timeInt = 0;
            
            int minutes = timeInt % 60;
            int hours = timeInt / 60;
            char minutesUnits = (minutes % 10) + '0';
            if (allowedChars.find(minutesUnits) == allowedChars.end())
                continue;
            minutes /= 10;
            char minutesTens = (minutes % 10) + '0';
            if (allowedChars.find(minutesTens) == allowedChars.end())
                continue;
            char hoursUnits = (hours % 10) + '0';
            if (allowedChars.find(hoursUnits) == allowedChars.end())
                continue;
            hours /= 10;
            char hoursTens = (hours % 10) + '0';
            if (allowedChars.find(hoursTens) == allowedChars.end())
                continue;
            string res = "";
            res += hoursTens + hoursUnits + ':' + minutesTens + minutesUnits;
            return res;
        }
        return "empty";
    }
};

int main()
{
    string input = "23:59";
    Solution().nextClosestTime(input);
    return 0;
}
