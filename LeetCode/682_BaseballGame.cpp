#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

int calPoints(vector<string>& ops)
{
    stack<int> myStack;

    for (string op : ops)
        if (op == "+") {
            int top = myStack.top();
            myStack.pop();
            int newTop = top + myStack.top();
            myStack.push(top);
            myStack.push(newTop);
        } 
        else if (op == "C")
            myStack.pop();
        else if (op == "D")
            myStack.push(myStack.top() << 1);
        else
            myStack.push(stoi(op));

    int res = 0;
    while (myStack.size()) {
        res += myStack.top();
        myStack.pop();
    }
    return res;
}