#include <cstdio>
#include <vector>

using namespace std;

/// TLE
///   Time complexity: O(n^2) preprocessing and O(1) per query
///   Space complexity: O(n^2)
class NumArray {
public:
    NumArray(vector<int> nums) {
        data = nums;

        for (int i = 0; i < data.size(); i++) {
            vector<int> temp(data.size(), 0);
            dp_sums.push_back(temp);
        }

        for (int i = 0; i < data.size(); i++)
            for (int j = i; j < data.size(); j++)
                if (i == j)
                    dp_sums[i][j] = data.at(i);
                else
                    dp_sums[i][j] = dp_sums[i][j - 1] + data.at(j);
    }
    
    int sumRange(int i, int j) {
        return dp_sums[i][j];
    }

private:
    vector<int> data;
    vector<vector<int>> dp_sums;
};

/// Accepted
///   Time Complexity: O(n) preprocessing, O(1) lookup
///   Space complexity: O(n)
class NumArrayLinear
{
    public:
        NumArrayLinear(vector<int> nums) {
            dp_sums = vector<int> (nums.size() + 1, 0);

            for (int i = 1; i < nums.size() + 1; i++)
                dp_sums[i] = dp_sums[i - 1] + nums.at(i - 1);
        }

        int sumRange(int i, int j) {
            return dp_sums[j + 1] - dp_sums[i];
        }

    private:
        vector<int> dp_sums;
};


int main()
{
    NumArray obj = NumArray({1, 2, 3, 4});
    int sum_13 = obj.sumRange(1, 3);

    printf("%d\n", sum_13);
    return 0;
}