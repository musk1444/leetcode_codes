class Solution {
public:
int n;
int solve(int index, int buy, vector<int>& prices, vector<vector<int>>& dp)
{
    if(index == n)
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
        // we are allowed to purchase
        int take = -prices[index] + solve(index+1,0,prices,dp);
        int not_take = 0 + solve(index+1, 1, prices,dp);
        profit = max(take, not_take);
    }
    else
    {
        // agar buy nhi kr skte
        // means we have to sell
        int take = prices[index] + solve(index+1, 1,prices,dp);
        int not_take = 0 + solve(index+1, 0, prices,dp);
        profit = max(take,not_take);
    }

    return dp[index][buy] = profit;
}
    int maxProfit(vector<int>& prices) {

        n = prices.size();

        vector<vector<int>> dp(n+1, vector<int>(2,-1));

        return solve(0,1,prices,dp);
        
    }
};