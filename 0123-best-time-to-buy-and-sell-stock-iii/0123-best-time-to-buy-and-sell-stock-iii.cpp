class Solution {
public:
    int n;

    int solve(vector<int>& prices, int index, int tr,
              vector<vector<int>>& dp) {
        if (index >= n  || tr == 4)
            return 0;

        // means we have exhausted our limit

        if (dp[index][tr] != -1) {
            return dp[index][tr];
        }

        int profit = INT_MIN;

        if (tr%2 == 0) {
            int take = -prices[index] + solve(prices, index + 1, tr+1, dp);
            int nottake = solve(prices, index + 1, tr, dp);

            profit = max(take, nottake);
        } else // you can sell
        {
            int take =
                +prices[index] + solve(prices, index + 1, tr+1, dp);
            int nottake = solve(prices, index + 1, tr, dp);

            profit = max(take, nottake);
        }

        return dp[index][tr] = profit;
    }

    int maxProfit(vector<int>& prices) {

        n = prices.size();

        vector<vector<int>> dp(n+1, vector<int>(4,-1));

        return solve(prices,0,0,dp);
        // index, buy, cap

        // vector<vector<vector<int>>> dp(
        //     n + 1, vector<vector<int>>(2, vector<int>(3, 0)));

        // for (int index = n - 1; index >= 0; index--) {
        //     for (int buy = 0; buy < 2; buy++) {
        //         for (int cap = 1; cap <= 2; cap++) {
        //             int profit = INT_MIN;

        //             if (buy == 1) {
        //                 int take = -prices[index] +
        //                            solve(prices, index + 1, 0, cap, dp);
        //                 int nottake = solve(prices, index + 1, 1, cap, dp);

        //                 profit = max(take, nottake);
        //             } else // you can sell
        //             {
        //                 int take = +prices[index] +
        //                            solve(prices, index + 1, 1, cap - 1, dp);
        //                 int nottake = solve(prices, index + 1, 0, cap, dp);

        //                 profit = max(take, nottake);
        //             }

        //             dp[index][buy][cap] = profit;
        //         }
        //     }
        // }

        // return dp[0][1][2];
    }
};