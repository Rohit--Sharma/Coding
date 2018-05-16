#include <cstdio>
#include <vector>
#include <map>
#include <set>

using namespace std;

bool containsNearbyDuplicate(vector<int>& nums, int k)
{
    map<int, int> m;

    for (int i = 0; i < nums.size(); i++)
        if (m.find(nums.at(i)) == m.end())
            m[nums.at(i)] = i;
        else
            if (i - m[nums.at(i)] > k)
                return true;

    return false;
}