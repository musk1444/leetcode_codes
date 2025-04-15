class Solution {
public:
    int solve(int n, vector<int>& dp) {
        if (n == 0) {
            return 0;
        }

        if (dp[n] != -1) {
            return dp[n];
        }

        int mincount = INT_MAX;
        for (int i = 1; i * i <= n; i++) {
            int result = 1 + solve(n - (i * i), dp);
            mincount = min(mincount, result);
        }

        return dp[n] = mincount;
    }
    int numSquares(int n) {
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0; // base case

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j * j <= i; j++) {
                dp[i] = min(dp[i], 1 + dp[i - j * j]);
            }
        }

        return dp[n];
    }
};