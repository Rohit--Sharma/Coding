#include <cstdio>
#include <vector>

using namespace std;

/// Remove duplicates in-place in the vector and return the count
int removeDuplicates(vector<int>& nums)
{
    int count = 0;

    int i, j = 1, temp;

    if (nums.size() >= 1) {
        temp = nums.at(0);
        count++;
    } else
        return count;
    
    for (i = 1; i < nums.size(); i++) {
        if (nums.at(i) != temp) {
            nums[j++] = nums.at(i);
            temp = nums.at(i);
            count++;
        }
    }

    return count;
}

int main()
{

    return 0;
}