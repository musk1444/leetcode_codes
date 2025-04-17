class Solution {
public:

bool solve(int i, int j, string& p, string& s,vector<vector<int>>& dp)
{
    // base cases
    if( i == 0 && j == 0)
    {
        // string 1 humari khatam h or 2 bhi khatam h -> hogya match
        return true;
    }
    if(i == 0 && j > 0)
    {
        // string 1 humari khatam h or 2 abhi nhi khatam h -> cannot match ab
        return false;
    }
    //an dekhte h aar string 2 khatam hogyi h to
    if(j == 0 && i > 0)
    {
        for(int idx = 1; idx <= i; idx++)
        {
            if(p[idx-1] != '*')
            {
                // agar kahi pe rbhi * value nai h to matlb nai ho skti matching
                return false;
            }
        }
        return true;
    }

    if(dp[i][j] != -1)
    {
        return dp[i][j];
    }

    if(p[i-1] == s[j-1] || p[i-1] == '?')
    {
        return dp[i][j] = solve(i-1, j-1, p, s,dp);
    }
    if(p[i-1] == '*')
    {
        // you will take both the cases:
        // where * equals to nothing
        // where * equals to one letter
        return dp[i][j] = (solve(i-1,j,p,s,dp) || solve(i, j-1,p,s,dp));
    }

    return dp[i][j]=  false; // agar abc or aec aise h, to b or e to kbhi match nai kr skte
}
    bool isMatch(string s, string p) {
        
        int n = p.length();
        int m = s.length();

        vector<vector<int>> dp(n+1, vector<int>(m+1,-1));
        // vector<vector<int>> dp(n+1, vector<int>(m+1,0));


        return solve(n,m,p,s,dp);

        // dp[0][0] = true;

        // for(int i = 0; i<=n; i++)
        // {

        // }

    }
};