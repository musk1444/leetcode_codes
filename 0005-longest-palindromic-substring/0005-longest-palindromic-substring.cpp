class Solution {
public:

bool solve(string& s, int i, int j)
{
    if(i >= j)
    {
        return true;
    }
    if(s[i] == s[j])
    {
        return solve(s,i+1,j-1);
    }



    return false;
}
    string longestPalindrome(string s) {

        int n = s.length();
        int maxlen = INT_MIN;
        int start = -1;

        for(int i = 0; i<n; i++)
        {
            for(int j = i; j<n; j++)
            {
                if(solve(s,i,j) == true && (j-i+1 > maxlen))
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