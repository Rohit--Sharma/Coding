#include <cstdio>
#include <vector>
#include <string>

using namespace std;

/// This works according it me, but it is giving wrong answer for a test case which works for local debugging even in leetcode
int compress(vector<char>& chars)
{
    bool firstChar = true;

    char newLetter;
    int count, pointer = 0;
    for (char c : chars) {
        if (newLetter == c) {
            count++;
            //cout << "Equal, old: " << c << " " << count << endl;
        }
        else {
            newLetter = c;
            if (firstChar) {
                firstChar = false;
                chars[pointer++] = newLetter;
            }
            else {
                //cout << "Not equal, old: " << c << " " << count << endl;
                if (count > 1) {
                    string intCount = to_string(count);
                    for (char intChar : intCount) {
                        chars[pointer++] = intChar;
                    }
                    chars[pointer++] = newLetter;
                }
                else {
                    chars[pointer++] = newLetter;
                }
            }
            count = 1;
        }
    }
    if (count > 1) {
        string intCount = to_string(count);
        for (char intChar : intCount) {
            chars[pointer++] = intChar;
        }
    }
    
    return pointer;
}

int compressSolution(vector<char>& chars)
{
    int anchor = 0, write = 0;
    for (int read = 0; read < chars.size(); read++)
        if (read + 1 == chars.size() || chars[read + 1] != chars[read]) {
            chars[write++] = chars[anchor];
            if (read > anchor)
                for (char c : to_string(read - anchor + 1))
                    chars[write++] = c;
            anchor = read + 1;
        }
    return write;
}