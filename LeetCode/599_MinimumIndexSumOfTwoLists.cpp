#include <cstdio>
#include <map>
#include <vector>
#include <string>
// #include <bits/stdc++.h>

using namespace std;

/// Time limit exceeded
vector<string> findRestaurant(vector<string>& list1, vector<string>& list2)
{
    vector<string> res;
    int i = 0, j = 0;
    int indexSum = 0;
    while (indexSum < list1.size() + list2.size()) {
        for (i = 0; i < list1.size(); i++)
            for (j = 0; j < list2.size(); j++)
                if (i + j > indexSum)
                    break;
                else
                    if (list1[i] == list2[j])
                        res.push_back(list1[i]);
        if (res.size() > 0)
            return res;
        indexSum++;
    }
    return res;
}

/// Time Complexity: O(l1 + l2)
vector<string> findRestaurantLinear(vector<string>& list1, vector<string>& list2)
{
    map<string, int> myMap;
    for (int i = 0; i < list1.size(); i++)
        myMap[list1[i]] = i;
    
    vector<string> res;
    int min_index_sum = INT_MAX, sum;
    for (int j = 0; j < list2.size() && j <= min_index_sum; j++) {
        if (myMap.find(list2[j]) != myMap.end()) {
            sum = j + myMap[list2[j]];
            if (sum < min_index_sum) {
                res.clear();
                res.push_back(list2[j]);
                min_index_sum = sum;
            }
            else if (sum == min_index_sum)
                res.push_back(list2[j]);
        }
    }
    return res;
}

int main()
{

    return 0;
}