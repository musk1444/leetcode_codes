class Solution {
public:

bool solve(string& s, int i, int j, vector<vector<int>>& dp)
{
    if(i >= j)
    {
        return 1;
    }

    if(dp[i][j] != -1)
    {
        return dp[i][j];
    }
    if(s[i] == s[j])
    {
        return dp[i][j] = solve(s,i+1,j-1,dp);
    }
    return dp[i][j] = 0;
}
    string longestPalindrome(string s) {

        int n = s.length();
        int maxlen = INT_MIN;
        int start = -1;

        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));

        for(int i = 0; i<n; i++)
        {
            for(int j = i; j<n; j++)
            {
                if(solve(s,i,j,dp) == true && (j-i+1 > maxlen))
                {
                    maxlen = j-i+1;
                    start = i;
                }
            }

        }

        // end me u return the substring starting from start index upto the maxlen
        return s.substr(start,maxlen);
        
        
    }
};