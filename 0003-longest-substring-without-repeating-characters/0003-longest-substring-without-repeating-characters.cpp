class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int n = s.length();
        unordered_map<char,int> hash;
        int l = 0;
        int r = 0;
        int maxlen = 0;
        while(r < n)
        {
            if(hash.count(s[r]) && hash[s[r]] >= l)
            {
                l = hash[s[r]] + 1;
            }

            hash[s[r]] = r;
            maxlen = max(maxlen, r- l +1);
            r++;

        }

        return maxlen;
    }
};