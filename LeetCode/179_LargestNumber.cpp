#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

bool comparator(string a, string b)
{
    return (b + a).compare(a + b);
}

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> strNums;
        for (int num : nums) {
            strNums.push_back(to_string(num));
        }

        sort(strNums.begin(), strNums.end(), comparator);

        if (strNums[0] == "0")
            return "0";
        
        string result;
        for (string str : strNums)
            result += str;
        return result;
    }
};

int main()
{
    vector<int> input;
    input = vector<int> {10, 2};
    cout << Solution().largestNumber(input) << endl;

    input = vector<int> {3, 30, 34, 5, 9};
    cout << Solution().largestNumber(input) << endl;
    return 0;
}