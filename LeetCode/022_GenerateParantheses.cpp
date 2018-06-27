#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

/// Accepted but very slow
///   Complexity: O(2^(2n)n)
class SolutionBruteForce 
{
    public:
        vector<string> generateParenthesis(int n) {
            vector<string> result;
            vector<char> temp(2 * n);
            generateAll(temp, 0, result);
            return result;
        }
    
    private:
        void generateAll(vector<char>& current, int pos, vector<string>& combinations) {
            if (pos == current.size()) {
                if (valid(current)) {
                    string res = string(current.begin(), current.end());
                    combinations.push_back(res);
                }
            }
            else {
                current[pos] = '(';
                generateAll(current, pos + 1, combinations);
                current[pos] = ')';
                generateAll(current, pos + 1, combinations);
            }
        }

        bool valid(vector<char> parantheses) {
            int bal = 0;
            for (char c : parantheses) {
                if (c == '(')
                    bal++;
                else
                    bal--;
                if (bal < 0)
                    return false;
            }
            return (bal == 0);
        }
};

/// Efficient implementation of the above algo. keep track of no of open and close brackets
///  added and only if a string is valid, proceed adding more brackets
///    Complexity: O(4^n/sqrt(n))
class Solution
{
    public:
        vector<string> generateParenthesis(int n) {
            vector<string> result;
            backtrack(result, "", 0, 0, n);
            return result;
        }

    private:
        void backtrack(vector<string>& combinations, string current, int open, int close, int max) {
            if (current.size() == 2 * max) {
                combinations.push_back(current);
                return;
            }

            if (open < max)
                backtrack(combinations, current + "(", open + 1, close, max);
            if (close < open)
                backtrack(combinations, current + ")", open, close + 1, max);
        }
};

int main()
{
    int n;
    cin >> n;
    auto results = Solution().generateParenthesis(n);

    for (string res : results)
        cout << res << " ";
    cout << endl;

    return 0;
}