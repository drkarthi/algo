class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int i, n=prices.size(), profit=0, max_profit=0, day_profit=0;
        for(i=1;i<n;i++) {
            day_profit = prices[i] - prices[i-1];
            profit += day_profit;
            if(profit<0)
                profit = 0;
            if(profit>=max_profit)
                max_profit = profit;
        }
        return max_profit;
    }
};