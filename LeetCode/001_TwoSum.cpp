#include <vector>
#include <cstdio>
#include <map>

using namespace std;

vector<int> twoSum_bruteforce(vector<int>& nums, int target) 
{
    vector<int> result;

    for (int i = 0; i < nums.size(); i++) {
        for (int j = 0; j < nums.size(); j++) {
            if ((i != j) && (nums[i] + nums[j] == target)) {
                result.push_back(i);
                result.push_back(j);
                return result;
            }
        }
    }

    return result;
}

vector<int> twoSum_hashTable_TwoPasses(vector<int>& nums, int target)
{
    vector<int> result;
    map<int, int> hashTable;

    for (int i = 0; i < nums.size(); i++) {
        // hashTable.emplace(nums[i], i);
        hashTable.insert(pair<int, int>(nums[i], i));
    }
    for (int i = 0; i < nums.size(); i++) {
        if ((hashTable.find(target - nums[i]) != hashTable.end()) && (hashTable[target - nums[i]] != i)) {
            result.push_back(i);
            result.push_back(hashTable[target - nums[i]]);
        }
    }

    return result;
}

vector<int> twoSum_hashTable_SinglePass(vector<int>& nums, int target)
{
    vector<int> result;
    map<int, int> hashTable;

    for (int i = 0; i < nums.size(); i++) {
        hashTable.insert(pair<int, int>(nums[i], i));

        if ((hashTable.find(target - nums[i]) != hashTable.end()) && (hashTable[target - nums[i]] != i)) {
            result.push_back(hashTable[target - nums[i]]);
            result.push_back(i);
        }
    }

    return result;
}

int main()
{
    // This kind of initialization works only in C++11. To Compile, use g++ -std=c++0x ...
    vector<int> array = {2, 7, 11, 15};

    vector<int> two_sum = twoSum_hashTable_SinglePass(array, 9);

    printf("%d %d\n", two_sum[0], two_sum[1]);

    return 0;
}