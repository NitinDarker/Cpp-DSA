// 121. Best Time to Buy and Sell Stock
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maxProfit(vector<int> &prices) {
        int mini = prices[0];
        int profit = 0;
        for (int i = 1; i < prices.size(); i++) {
            int cost = prices[i] - mini;
            profit = max(profit, cost);
            mini = min(mini, prices[i]);
        }
        return profit;
    }
};
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/