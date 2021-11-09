#include <vector>
#include <iostream>
using namespace std;

int maxProfit(vector<int> &prices)
{
    int n = prices.size(), profit = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            profit = max(profit, prices[i] - prices[j]);
        }
    }
    return profit;
}