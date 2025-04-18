class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int mini = prices[0];
        int profit = 0;
        int n = prices.size();

        for(int i = 1; i<n; i++)
        {
            int cost = prices[i] - mini;
            profit = max(profit, cost);
            // now we need to updare the mini value
            mini = min(mini, prices[i]);
        }

        return profit;
        
    }
};