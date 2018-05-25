#include <cstdio>
#include <string>

using namespace std;

int countSegments(string s)
{
    int count = 0;
    for (int i = 0; i < s.size(); i++)
        if ((i == 0 || s[i - 1] == ' ') && s[i] != ' ')
            count++;
    return count;
}