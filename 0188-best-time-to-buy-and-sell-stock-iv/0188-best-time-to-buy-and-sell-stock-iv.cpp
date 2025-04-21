class Solution {
public:
    int n;

    int solve(int index, int buy, int cap, vector<int>& prices,
              vector<vector<vector<int>>>& dp) {
        if (cap == 0) {
            return 0;
        }
        if (index == n) {
            return 0;
        }
        if (dp[index][buy][cap] != -1) {
            return dp[index][buy][cap];
        }

        int profit = INT_MIN;
        if (buy == 1) {
            int take = -prices[index] + solve(index + 1, 0, cap, prices, dp);
            int nottake = 0 + solve(index + 1, 1, cap, prices, dp);
            profit = max(take, nottake);
        } else {
            int take =
                +prices[index] + solve(index + 1, 1, cap - 1, prices, dp);
            int nottake = 0 + solve(index + 1, 0, cap, prices, dp);
            profit = max(take, nottake);
        }

        return dp[index][buy][cap] = profit;
    }
    int maxProfit(int k, vector<int>& prices) {

        n = prices.size();

        // vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2,
        // vector<int>(k+1,-1))); return solve(0,1,k,prices,dp); index, maxlimit

        vector<vector<int>> after(2, vector<int>(k + 1, 0));
        vector<vector<int>> curr(2, vector<int>(k + 1, 0));
        

        for (int index = 0; index <= n; index++) {
            for (int buy = 0; buy < 2; buy++) {
                curr[buy][0] = 0;
            }
        }
        for (int buy = 0; buy < 2; buy++) {
            for (int cap = 0; cap <= k; cap++) {
                curr[buy][cap] = 0;
            }
        }
        // we have dealt with the base cases

        for (int index = n - 1; index >= 0; index--) {
            for (int buy = 0; buy < 2; buy++) {
                for (int cap = 1; cap <= k ;cap++) {
                    int profit = INT_MIN;
                    if (buy == 1) {
                        int take = -prices[index] + after[0][cap];
                        int nottake = 0 + after[1][cap];
                        profit = max(take, nottake);
                    } else {
                        int take = +prices[index] + after[1][cap - 1];
                        int nottake = 0 + after[0][cap];
                        profit = max(take, nottake);
                    }

                    curr[buy][cap] = profit;
                }
            }
            after = curr;
        }

        return after[1][k];
    }
};