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
    string numberToWords(int num) {
        if (num == 0)
            return "Zero";
        
        string result;
        int i = 0;
        while (num) {
            int curr = num % 1000;
            
            string englishSubstr = smallStrToWords(curr);

            // Remove the trailing white spaces
            while (!englishSubstr.empty() && isspace(englishSubstr.back())) 
                englishSubstr.pop_back();
            
            result = englishSubstr + ' ' + ten_terms[i++] + ' ' + result; 
            num /= 1000;
        }

        // Remove the trailing white spaces
        while (!result.empty() && isspace(result.back())) 
            result.pop_back();

        return result;
    }
    
private:
    vector<string> ones = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
    
    vector<string> tens = {"", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    
    vector<string> special_tens_teens = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    
    vector<string> ten_terms = {"", "Thousand", "Million", "Billion"};
    
    /// Converts the 3 digit number to its string form
    string smallStrToWords(int num) {
        if (num < 10)
            return ones[num];
        else if (num < 20)
            return special_tens_teens[num - 10];
        else if (num < 100)
            return tens[num / 10] + " " + smallStrToWords(num % 10);
        else if (num < 1000)
            return ones[num / 100] + " Hundred " + smallStrToWords(num % 100);
    }
};

int main() {
    int inp;
    cin >> inp;
    cout << Solution().numberToWords(inp) << endl;

    return 0;
}