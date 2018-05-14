#include <cstdio>
#include <vector>
#include <map>

using namespace std;

/// Time: O(n), Space: O(n)
int singleNumber(vector<int>& nums)
{
    map<int, int> m;
    for (int i = 0; i < nums.size(); i++) {
        if (m.find(nums.at(i)) == m.end())
            m[nums.at(i)];
        else
            m.erase(m.find(nums.at(i)));
    }
    return (m.begin())->first;
}

/// Time: O(n), Space: O(1)
///    For a bit, b: 0 xor b = b and b xor b = 0
int singleNumberEfficient(vector<int>& nums)
{
    int result = 0;
    for (int i = 0; i < nums.size(); i++)
        result ^= nums.at(i);
    return result;
}

int main()
{
    vector<int> v;
    v.push_back(2);
    v.push_back(2);
    v.push_back(1);

    printf("%d\n", singleNumber(v));

    return 0;
}