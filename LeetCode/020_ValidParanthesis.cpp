#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> myStack;
        for (char ch : s) {
            switch (ch) {
                case '(':
                    myStack.push(')');
                    break;
                case '[':
                    myStack.push(']');
                    break;
                case '{':
                    myStack.push('}');
                    break;
                default:
                    if (myStack.empty() || myStack.top() != ch)
                        return false;
                    else
                        myStack.pop();
            }
        }
        return myStack.empty();
    }
};

int main()
{
    string input;

    input = "([]{()})";
    cout << Solution().isValid(input) << endl;

    input = "()[]{}";
    cout << Solution().isValid(input) << endl;

    input = ")";
    cout << Solution().isValid(input) << endl;
    
    input = "[";
    cout << Solution().isValid(input) << endl;

    input = "";
    cout << Solution().isValid(input) << endl;

    input = "([)]";
    cout << Solution().isValid(input) << endl;

    return 0;
}