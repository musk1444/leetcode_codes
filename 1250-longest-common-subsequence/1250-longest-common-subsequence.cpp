class Solution {
public:

int solve(int index1, int index2, string& text1, string& text2, vector<vector<int>>& dp)
{
    // base case
    // when either of teh indices becomes negative
    if(index1 < 0 || index2 < 0)
    {
        return 0;
    }

    if(dp[index1][index2] != -1)
    {
        return dp[index1][index2];
    }

    if(text1[index1] == text2[index2])
    {
        return 1 + solve(index1 - 1, index2 - 1, text1, text2,dp);
    }

    return dp[index1][index2] = (0 + max(solve(index1 - 1, index2, text1, text2,dp), solve(index1, index2 - 1, text1,text2,dp))); 
}
    int longestCommonSubsequence(string text1, string text2) {
        
        int n = text1.length();
        int m = text2.length();

        vector<vector<int>> dp(n+1, vector<int>(m+1,-1));

        return solve(n-1, m-1,text1, text2, dp);
    }
};