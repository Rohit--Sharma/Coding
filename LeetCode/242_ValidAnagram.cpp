#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

bool isAnagram(string s, string t)
{
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    return (s == t);
}

int main()
{

    return 0;
}