/*
Leetcode : 121 {https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/}

price[i] is the price of a given stock on the ith day.
I/P : [7 , 1, 5, 3, 6, 4]
Day    0   1  2  3  4  5
           .        .
Buy  on day: 1 // C.P
Sell on day: 4 // S.P
Profit = S.P - C.P
          6    1 
O/P :       5
i.e Return the best time to buy and sell stock.
Return the max profit that can be achieved from the transaction.
Basic logic: buy the stock at the least price and sell at highest possible price

*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int profit = 0;
        int minPrice = INT_MAX;
        for(int i = 0; i < n; i++) {
            minPrice = min(minPrice, prices[i]);
            profit = max(profit, prices[i] - minPrice);
        }
        return profit;
    }

};