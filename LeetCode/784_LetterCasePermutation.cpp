#include <iostream>
#include <vector>
#include <string>

using namespace std;

void combinationUtil(string input, vector<int> arr, vector<int> data, int start, int end, int index, int r, vector<string>& res)
{
    if (index == r) {
        string temp = input;
        for (int i = 0; i < r; i++)
            temp[data[i]] -= 32;        // Convert to uppercase
        res.push_back(temp);
        return;
    }
    
    for (int i = start; i <= end && end - i + 1 >= r - index; i++) {
        data[index] = arr[i];
        combinationUtil(input, arr, data, i + 1, end, index + 1, r, res);
    }
}

// Inspired by https://www.geeksforgeeks.org/print-all-possible-combinations-of-r-elements-in-a-given-array-of-size-n/ GeeksForGeeks
void printCombinations(string input, vector<int> arr, int r, vector<string>& res)
{
    vector<int> data(r);
    combinationUtil(input, arr, data, 0, arr.size() - 1, 0, r, res);
}

vector<string> letterCasePermutation(string S)
{
    vector<string> result;

    vector<int> indices;
    for (int i = 0; i < S.size(); i++) {
        if (S[i] >= '0' && S[i] <= '9')
            continue;
        S[i] = tolower(S[i]);
        indices.push_back(i);
    }

    // Change i chars at a time
    for (int i = 0; i <= indices.size(); i++)
        printCombinations(S, indices, i, result);

    return result;
}

int main()
{
    string input;
    cin >> input;

    auto res = letterCasePermutation(input);

    for (auto str : res)
        cout << str << " ";
    cout << endl;

    return 0;
}