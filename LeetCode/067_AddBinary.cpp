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

class Solution_Accepted
{
  public:
    string addBinary(string a, string b)
    {
        string res;

        if (b.size() > a.size())
        {
            string temp = a;
            a = b;
            b = temp;
        }

        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());

        int carry = 0, i;
        for (i = 0; i < a.size(); i++)
        {
            int sum = 0;
            if (i < b.size())
            {
                sum = a[i] - '0' + b[i] - '0' + carry;
            }
            else
            {
                sum = a[i] - '0' + carry;
            }
            switch (sum)
            {
            case 0:
                res.push_back('0');
                carry = 0;
                break;
            case 1:
                res.push_back('1');
                carry = 0;
                break;
            case 2:
                res.push_back('0');
                carry = 1;
                break;
            case 3:
                res.push_back('1');
                carry = 1;
                break;
            }
        }

        if (carry == 1)
            res.push_back('1');

        reverse(res.begin(), res.end());
        return res;
    }
};

class Solution_Elegant
{
  public:
    string addBinary(string a, string b)
    {
        string res = "";
        
        int i = a.size() - 1, j = b.size() - 1;
        int carry = 0;
        while (i >= 0 || j >= 0 || carry == 1) {
            int sum = 0;
            sum += (i >= 0) ? a[i--] - '0' : 0;
            sum += (j >= 0) ? b[j--] - '0' : 0;
            sum += carry;
            res = char((sum % 2) + '0') + res;
            carry = sum / 2;
        }

        return res;
    }
};

int main()
{
    string a, b;
    
    a = "11";
    b = "1";
    cout << Solution_Elegant().addBinary(a, b) << endl;
    
    a = "1";
    b = "11";
    cout << Solution_Elegant().addBinary(a, b) << endl;
    
    a = "1010";
    b = "1011";
    cout << Solution_Elegant().addBinary(a, b) << endl;

    a = "10010";
    b = "110";
    cout << Solution_Elegant().addBinary(a, b) << endl;
    return 0;
}