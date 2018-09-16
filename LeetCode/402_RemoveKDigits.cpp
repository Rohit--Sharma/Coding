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
    string removeKdigits(string num, int k) {
        if (num.size() == k) {
            return "0";
        }
        string result;
        stack<char> my_stack;
        int n_pops = 0;
        for (char x : num) {
            if (my_stack.empty()) {
                //cout << "Push: " << x << endl;
                my_stack.push(x);
            }
            else {
                char stack_top = my_stack.top();
                while (n_pops < k && stack_top > x) {
                    //cout << "Pop: " << stack_top << endl;
                    my_stack.pop();
                    n_pops++;
                    if (my_stack.empty())
                        break;
                    stack_top = my_stack.top();
                }
                my_stack.push(x);
            }
        }
        while (n_pops < k) {
            my_stack.pop();
            n_pops++;
        }

        //cout << "Stack size: " << my_stack.size() << endl;

        string rev_res;
        while (!my_stack.empty()) {
            //cout << "RevTop: " << my_stack.top() << endl;
            rev_res += my_stack.top();
            my_stack.pop();
        }

        int i = rev_res.size() - 1;
        while (rev_res[i--] == '0');
        i++;
        for (; i >= 0; i--) {
            result += rev_res[i];
        }
        return result.empty() ? "0" : result;
    }
};

int main()
{
    string in_num;
    int in_k;

    in_num = "1432219"; in_k = 3;
    cout << Solution().removeKdigits(in_num, in_k) << endl;

    in_num = "10200"; in_k = 1;
    cout << Solution().removeKdigits(in_num, in_k) << endl;

    in_num = "10"; in_k = 2;
    cout << Solution().removeKdigits(in_num, in_k) << endl;

    return 0;
}