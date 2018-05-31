#include <cstdio>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

/// Can also be solved in constant space
vector<int> findErrorNums(vector<int>& nums)
{
    vector<int> res;
    map<int, int> myMap;
    for (int num : nums)
        if (myMap.find(num) == myMap.end())
            myMap[num] = 1;
        else
            res.push_back(num);
            
    int sum = 0;
    for (auto start = myMap.begin(); start != myMap.end(); start++)
        sum += start->first;
    int len = nums.size();
    res.push_back(len * (len + 1) / 2 - sum);
    return res;
}

int main()
{
    vector<int> input {1, 2, 2, 4};
    auto res = findErrorNums(input);
    cout << res[0] << ", " << res[1] << endl;
    return 0;
}