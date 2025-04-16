class Solution {
public:

int solve(int i, int j, string& s, string& t, vector<vector<int>>& dp)
{
    // base case
    if(j==0)
    {
        // means we have found a match for all of the tsr2
        return 1;
    }
    if(i == 0)
    {
        return 0;
        // we have exhausted our str1 but mila nai match
    }

    if(dp[i][j] != -1)
    {
        return dp[i][j];
    }

    if(s[i-1] == t[j-1])
    {
        // match milggya hume
        return (solve(i-1,j-1,s,t,dp) + solve(i-1,j,s,t,dp));
    }
    
    return dp[i][j] = solve(i-1,j,s,t,dp);
   
}
    int numDistinct(string s, string t) {

        int n = s.length();
        int m = t.length();

        vector<vector<long long>> dp(n+1, vector<long long>(m+1,0));

        // return solve(n, m, s, t,dp);
        for(int i = 0; i<=n; i++)
        {
            dp[i][0] = 1;
        }
        for(int j = 1; j<=m; j++)
        {
            dp[0][j] = 0;
        }
        // we will loop through normally
        for(int i = 1; i<=n; i++)
        {
            for(int j = 1; j<=m; j++)
            {
                if(s[i-1] == t[j-1])
                {
                    if(dp[i-1][j-1] <= 1e10 && dp[i-1][j] <= 1e10)
                    dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                }
                else
                {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        
        return (int) dp[n][m];
    }
};