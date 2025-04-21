class Solution {
public:
    int n;

    int solve(int index, int buy, vector<int>& prices, int fee,
              vector<vector<int>>& dp) {
        if (index >= n) {
            return 0;
        }

        if (dp[index][buy] != -1) {
            return dp[index][buy];
        }

        int profit = INT_MIN;
        if (buy == 1) {
            int take =
                -prices[index] - fee + solve(index + 1, 0, prices, fee, dp);
            int nottake = 0 + solve(index + 1, 1, prices, fee, dp);

            profit = max(take, nottake);
        } else // you can sell, now you can choose from either seeling or not
               // selling
        {
            int take = +prices[index] + solve(index + 1, 1, prices, fee, dp);
            int nottake = 0 + solve(index + 1, 0, prices, fee, dp);

            profit = max(take, nottake);
        }

        return dp[index][buy] = profit;
    }
    int maxProfit(vector<int>& prices, int fee) {

        n = prices.size();

        // vector<vector<int>> dp(n+1, vector<int>(2, -1));
        // return solve(0,1,prices,fee,dp);

        vector<int> after(2, 0);
        vector<int> curr(2, 0);


        for (int buy = 0; buy < 2; buy++) {
            curr[buy] = 0;
        }

        for (int index = n - 1; index >= 0; index--) {
            for (int buy = 0; buy < 2; buy++) {
                int profit = INT_MIN;
                if (buy == 1) {
                    int take = -prices[index] - fee + after[0];
                    int nottake = 0 + after[1];

                    profit = max(take, nottake);
                } else // you can sell, now you can choose from either seeling
                       // or not selling
                {
                    int take = +prices[index] + after[1];
                    int nottake = 0 + after[0];

                    profit = max(take, nottake);
                }

                curr[buy] = profit;
            }
            after = curr;
        }

        return after[1];
    }
};