#include <cstdio>
#include <vector>
#include <map>
#include <set>

using namespace std;

bool containsDuplicate(vector<int>& nums)
{
    map<int, int> m;

    for (int n : nums)
        if (m.find(n) == m.end())
            m[n] = 1;
        else
            return true;

    return false;
}

bool containsDuplicateSets(vector<int>& nums)
{
    set<int> mySet (nums.begin(), nums.end());

    return (mySet.size() == nums.size() ? false : true);
}