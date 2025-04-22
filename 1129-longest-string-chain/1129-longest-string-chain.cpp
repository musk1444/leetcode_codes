class Solution {
public:

bool  ispossible(string &s1, string &s2)
{
    // s1 is teh new string
    // s2 is the previous one
    if(s1.length() != s2.length() + 1)
    {
        return false;
    }
    int first = 0;
    int second = 0;

    while(first < s1.size())
    {
        if(second<s2.size() && s1[first] == s2[second])
        {
            first++;
            second++;
        }
        else
        {
            first++;
        }
    }

    return (first == s1.size() && second == s2.size());

}
    int longestStrChain(vector<string>& words) {

        int n = words.size();
        sort(words.begin(), words.end(), [](const string &a, const string &b) {
            return a.length() < b.length();
        });

        int maxi = 1;
        vector<int> dp(n,1);

        for(int index = 0; index<n; index++)
        {
            for(int prev = 0; prev<index; prev++)
            {
                if(ispossible(words[index], words[prev]) && 1+dp[prev] > dp[index])
                {
                    dp[index] = 1+dp[prev];
                }
            }
            maxi = max(maxi, dp[index]);
        }

        return maxi;
    }
};