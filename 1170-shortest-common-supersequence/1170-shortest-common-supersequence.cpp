class Solution {
public:


    string shortestCommonSupersequence(string str1, string str2) {

        int n = str1.length();
        int m = str2.length();

    vector<vector<int>> dp(n+1, vector<int>(m+1,0));
    for(int i = 0; i<=n; i++)
    {
        dp[i][0] = 0;
    }
    for(int j = 0; j<=m; j++)
    {
        dp[0][j] = 0;
    }

    for(int i = 1; i<=n; i++)
    {
        for(int j = 1; j<=m; j++)
        {
            if(str1[i-1] == str2[j-1])
            {
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else
            {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

        string result;
        int i = n;
        int j = m;

        while(i>0 && j>0)
        {
            if(str1[i-1] == str2[j-1])
            {
                result += str1[i-1];
                i--;
                j--;
                // we add only once as both the values are equal
            }
            else if(dp[i-1][j] > dp[i][j-1])
            {
                // we take the max value
                result  += str1[i-1];
                i--;
            }
            else
            {
                // we tak ethe jth character
                result+= str2[j-1];
                j--;
            }
        }
        // if we still have any characters left in our string
        while(i > 0)
        {
            result += str1[i-1];
            i--;
        } 
        while(j > 0)
        {
            result += str2[j-1];
            j--;
        }

        reverse(result.begin(), result.end());

        return result;
        
    }
};