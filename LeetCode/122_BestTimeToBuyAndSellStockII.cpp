#include <cstdio>
#include <vector>

using namespace std;

int maxProfit(vector<int>& prices)
{
    if (prices.size() == 0)
        return 0;
    int i = 0;
    int valley, peak;
    valley = peak = prices.at(0);

    int maxProfit = 0;
    while (i < prices.size() - 1) {
        while (i < prices.size() - 1 && prices.at(i) >= prices.at(i + 1))
            i++;
        valley = prices.at(i);

        while (i < prices.size() - 1 && prices.at(i) <= prices.at(i + 1))
            i++;
        peak = prices.at(i);

        maxProfit += peak - valley;
    }

    return maxProfit;
}

int maxProfitSimple(vector<int>& prices)
{
    int maxProfit = 0;
    for (int i = 1; i < prices.size(); i++)
        if (prices.at(i - 1) <= prices.at(i))
            maxProfit += prices.at(i) - prices.at(i - 1);
    return maxProfit;
}

int main()
{

    return 0;
}