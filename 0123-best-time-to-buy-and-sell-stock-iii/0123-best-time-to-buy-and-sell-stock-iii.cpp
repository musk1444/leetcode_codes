class Solution {
public:
int n;

int solve(int index, int tr, vector<int>& prices, vector<vector<int>>& dp)
{
    if(index == n || tr == 4)
    {
        return 0;
    }
    if(dp[index][tr] != -1)
    {
        return dp[index][tr];
    }
    int profit = INT_MIN;

    if(tr % 2 == 0) // even index means we can buy
    {
        int take = -prices[index] + solve(index+1, tr+1,prices,dp);
        int nottake = 0 + solve(index+1, tr,prices,dp);
        profit = max(take,nottake);

    }
    else
    {
        int take = +prices[index] + solve(index+1, tr+1,prices,dp);
        int nottake = 0 + solve(index+1, tr,prices,dp);
        profit = max(take,nottake);
    }

    return dp[index][tr] = profit;
}
    int maxProfit(vector<int>& prices) {

        n = prices.size();

        // vector<vector<int>> dp(n+1, vector<int>(4,-1));
        vector<vector<int>> dp(n+1, vector<int>(4,0));

        // return solve(0,0, prices,dp);
        // index, transaction

        for(int tr =0; tr<4; tr++)
        {
            dp[n][tr] = 0;
        }
       

        for(int index = n-1; index >=0; index--)
        {
            for(int tr = 0; tr<4; tr++)
            {
                int profit = INT_MIN;

                if(tr % 2 == 0) // even index means we can buy
                {
                    int take = -prices[index] + solve(index+1, tr+1,prices,dp);
                    int nottake = 0 + solve(index+1, tr,prices,dp);
                    profit = max(take,nottake);

                }
                else
                {
                    int take = +prices[index] + solve(index+1, tr+1,prices,dp);
                    int nottake = 0 + solve(index+1, tr,prices,dp);
                    profit = max(take,nottake);
                }
                dp[index][tr] = profit;
            }
        }
        
        return dp[0][0];
    }
};