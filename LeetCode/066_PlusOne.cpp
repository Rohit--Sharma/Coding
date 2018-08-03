#include <iostream>
#include <vector>
#include <string>

using namespace std;

/// Wrong Answer: Convert to int and then solve. Can fail when integer overflows
class Solution_ConvertToInt {
public:
    vector<int> plusOne(vector<int>& digits) {
        return numberToDigits(digitsToNumber(digits) + 1);
    }

private:
    int digitsToNumber(vector<int> digits) {
        int res = 0, loc = 1;
        for (int i = digits.size() - 1; i >= 0; i--) {
            res += digits[i] * loc;
            loc *= 10;
        }
        return res;
    }

    vector<int> numberToDigits(int num) {
        vector<int> res;
        if (num == 0) {
            res.push_back(0);
            return res;
        }
        while (num) {
            res.push_back(num % 10);
            num /= 10;
        }
        vector<int> answer;
        for (int i = res.size() - 1; i >= 0; i--)
            answer.push_back(res[i]);
        return answer;
    }
};

/// Accepted
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> res;
        int carry = 1;
        for (int i = digits.size() - 1; i >= 0; i--) {
            if (digits[i] + carry == 10) {
                res.push_back(0);
            }
            else {
                res.push_back(digits[i] + carry);
                carry = 0;
            }
        }
        if (carry == 1)
            res.push_back(1);

        vector<int> answer;
        for (int i = res.size() - 1; i >= 0; i--)
            answer.push_back(res[i]);
        return answer;
    }
};

/// Awesome implementation from discussions
class Solution_Crisp {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        for (int i = n - 1; i >= 0; i--) {
            if (digits[i] < 9) {
                digits[i]++;
                return digits;
            }
            
            digits[i] = 0;
        }
        
        vector<int> newNumber (n + 1, 0);
        newNumber[0] = 1;
        return newNumber;
    }
};

int main()
{
    vector<int> input;

    input = vector<int> {1, 2, 3};
    auto res = Solution_Crisp().plusOne(input);
    for (int dig : res)
        cout << dig << " ";
    cout << endl;

    input = vector<int> {4, 3, 2, 1};
    res = Solution_Crisp().plusOne(input);
    for (int dig : res)
        cout << dig << " ";
    cout << endl;

    input = vector<int> {4, 3, 9, 9};
    res = Solution_Crisp().plusOne(input);
    for (int dig : res)
        cout << dig << " ";
    cout << endl;

    input = vector<int> {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    res = Solution_Crisp().plusOne(input);
    for (int dig : res)
        cout << dig << " ";
    cout << endl;

    input = vector<int> {9, 9, 9};
    res = Solution_Crisp().plusOne(input);
    for (int dig : res)
        cout << dig << " ";
    cout << endl;

    input = vector<int> {3, 9, 9};
    res = Solution_Crisp().plusOne(input);
    for (int dig : res)
        cout << dig << " ";
    cout << endl;

    return 0;
}