class Solution {
public:
int n;

int solve(vector<int>& prices, int index, int buy, vector<vector<int>>& dp)
{
    if(index >= n)
    {
        return 0;
    }
    if(dp[index][buy] != -1)
    {
        return dp[index][buy];
    }

    int profit = INT_MIN;
    if(buy == 1)
    {
        // we can buy so we choose either to buy or not buy
        int take = -prices[index] + solve(prices,index+1,0,dp);
        int not_take = solve(prices,index+1,1,dp);

        profit = max(take,not_take);

    }

    else // we want to sell
    {
        // we will either sell or not sell
        int take = prices[index] + solve(prices,index+1,1,dp);
        int not_take = solve(prices,index+1,0,dp);

        profit = max(take,not_take);
    }

    return dp[index][buy] = profit;
}
    int maxProfit(vector<int>& prices) {

        n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2,-1));

        return solve(prices,0,1,dp);

        
    }
};