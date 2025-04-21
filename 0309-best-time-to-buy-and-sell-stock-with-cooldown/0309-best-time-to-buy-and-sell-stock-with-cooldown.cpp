class Solution {
public:
    int n;

    int solve(int index, int buy, vector<int>& prices,
              vector<vector<int>>& dp) {
        if (index >= n) {
            return 0;
        }
        if (dp[index][buy] != -1) {
            return dp[index][buy];
        }

        int profit = INT_MIN;

        if (buy == 1) {
            int take = -prices[index] + solve(index + 1, 0, prices, dp);
            int nottake = 0 + solve(index + 1, 1, prices, dp);
            profit = max(take, nottake);
        } else {
            int take = +prices[index] + solve(index + 2, 1, prices, dp);
            int nottake = 0 + solve(index + 1, 0, prices, dp);
            profit = max(take, nottake);
        }
        return dp[index][buy] = profit;
    }
    int maxProfit(vector<int>& prices) {

        n = prices.size();

        // vector<vector<int>> dp(n+1, vector<int>(2,-1));

        // return solve(0, 1,prices,dp);

        vector<vector<int>> dp(n + 2, vector<int>(2, 0));

      

        for (int index = n - 1; index >= 0; index--) {
            for (int buy = 0; buy < 2; buy++) {
                int profit = INT_MIN;

                if (buy == 1) {
                    int take = -prices[index] + dp[index + 1][0];
                    int nottake = 0 + dp[index + 1][1];
                    profit = max(take, nottake);
                } else {
                    int take = prices[index] + dp[index + 2][1];
                    int nottake = 0 + dp[index + 1][0];
                    profit = max(take, nottake);
                }
                dp[index][buy] = profit;
            }
        }
        return dp[0][1];
    }
};