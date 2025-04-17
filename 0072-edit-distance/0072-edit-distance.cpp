class Solution {
public:

int solve(int i, int j, string& s, string& t,vector<vector<int>>& dp)
{
    if(i == 0)
    {
        return j;
    }
    if(j == 0)
    {
        return i;
    }

    if(dp[i][j] != -1)
    {
        return dp[i][j];
    }

    if(s[i-1] == t[j-1])
    {
        // if the characters are equal, then we simple move back
        return dp[i][j] =  (0+ solve(i-1,j-1,s,t,dp));
    }
    // if thecharacters are not equal, we need ot take care of all teh thre ecases
    int insertion = 1 + solve(i,j-1,s,t,dp);
    int deletion = 1 + solve(i-1,j, s, t,dp);
    int replace = 1 + solve(i-1, j-1, s,t,dp);

    return dp[i][j] = min({insertion, deletion, replace});
}
    int minDistance(string word1, string word2) {

        int n = word1.length();
        int m = word2.length();

        vector<vector<int>> dp(n+1, vector<int>(m+1,-1));

        return solve(n,m,word1,word2,dp);
        
    }
};