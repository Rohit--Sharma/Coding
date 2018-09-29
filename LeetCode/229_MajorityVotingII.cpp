#include <cstdio>

using namespace std;

// Similar to Boyer-Moore majority voting algorithm
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int candidate_a = 0, candidate_b = 0, count_a = 0, count_b = 0;
        
        for (int num : nums) {
            if (count_a == 0 && candidate_b != num)
                candidate_a = num;
            else if (count_b == 0 && candidate_a != num)
                candidate_b = num;
            
            if (num == candidate_a)
                count_a++;
            else if (num == candidate_b)
                count_b++;
            else {
                count_a--;
                count_b--;
            }
        }
        
        count_a = count_b = 0;
        for (int num : nums)
            if (num == candidate_a)
                count_a++;
            else if (num == candidate_b)
                count_b++;
        
        vector<int> result;
        if (count_a > nums.size() / 3)
            result.push_back(candidate_a);
        if (count_b > nums.size() / 3)
            result.push_back(candidate_b);
        
        return result;
    }
};

int main() {

	return 0;
}