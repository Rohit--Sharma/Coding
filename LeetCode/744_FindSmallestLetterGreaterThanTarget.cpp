#include <cstdio>
#include <vector>
#include <iostream>
#include <map>
using namespace std;

char nextGreatestLetter(vector<char>& letters, char target)
{
    vector<bool> arr(26, false);

    for (char ch : letters)
        arr[ch - 'a'] = true;
    
    int j = target - 'a' + 1;
    for (int i = 0; i < 26; i++, j++) {
        if (arr[j % 26] == true)
            return j % 26 + 'a';
    }
}

int main()
{
    vector<char> input {'c', 'f', 'j'};
    char target;
    cin >> target;
    cout << nextGreatestLetter(input, target) << endl;
    return 0;
}