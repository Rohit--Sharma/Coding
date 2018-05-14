#include <cstdio>
#include <vector>
#include <limits>

using namespace std;

/// O(n^2) implementation
int maxProfitBruteforce(vector<int>& prices)
{
    int profit = 0, n = prices.size();

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (prices.at(j) - prices.at(i) > profit)
                profit = prices.at(j) - prices.at(i);
        }
    }

    return profit;
}

/// O(n) implementation
int maxProfitEfficient(vector<int>& prices)
{
    int minPrice = numeric_limits<int>::max();
    int maxProfit = 0;

    for (int i = 0; i < prices.size(); i++) {
        if (prices[i] < minPrice)
            minPrice = prices.at(i);
        else if (prices.at(i) - minPrice > maxProfit)
            maxProfit = prices.at(i) - minPrice;
    }

    return maxProfit;
}

int main()
{

    return 0;
}