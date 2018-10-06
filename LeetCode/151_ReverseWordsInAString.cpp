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
    void reverseWords(string &s) {
        string res = "";
        int i = 0, j = s.size() - 1;
        while (s[i] == ' ')
            i++;
        while (s[j] == ' ')
            j--;
        while (i <= j) {
            int start = i;
            while (i <= j && s[i] != ' ')
                i++;
            res += reverseStr(s, start, i - 1);
			if (i <= j)
	            res += " ";
            while (i <= j && s[i] == ' ')
                i++;
        }
        
        s = reverseStr(res, 0, res.size() - 1);
    }
    
private:
    string reverseStr(string s, int start, int end) {
		int i = start, j = end;
        while (i < j) {
            char temp = s[i];
            s[i] = s[j];
            s[j] = temp;
            
            i++;
            j--;
        }
        return string(s, start, end - start + 1);
    }
};

int main() {
	string input = "the sky is blue";
	Solution().reverseWords(input);
	cout << input << endl;

	input = "    my      name     is  khan   ";
	Solution().reverseWords(input);
	cout << input << endl;

    return 0;
}