#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minCost(vector<int>& cost, vector<int>& costDp, int index)
{
    if (costDp[index] != -1)
        return costDp[index];

    costDp[index] = min(minCost(cost, costDp, index - 1) + cost[index - 1], minCost(cost, costDp, index - 2) + cost[index - 2]);
    return costDp[index];
}

int minCostClimbingStairs(vector<int>& cost)
{
    vector<int> costToClimbDp(cost.size() + 1, -1);
    costToClimbDp[0] = costToClimbDp[1] = 0;

    return minCost(cost, costToClimbDp, cost.size());
}

int main()
{
    vector<int> input {10, 15, 20};
    cout << minCostClimbingStairs(input) << endl;

    vector<int> input2 {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    cout << minCostClimbingStairs(input2) << endl;
    return 0;
}