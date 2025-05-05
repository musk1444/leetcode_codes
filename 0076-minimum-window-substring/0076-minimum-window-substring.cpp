class Solution {
public:
    string minWindow(string s, string t) {

        int n = s.length();
        int m = t.length();

        if(m > n) return "";
        unordered_map<char,int> mpp;
        for(auto &ch:t)
        {
            mpp[ch]++;
        }
        int i = 0;
        int j = 0;
        int reqcount = m;
        int start_i = 0;
        int minwindow = INT_MAX;

        while(j<n)
        {
            char ch = s[j];
            if(mpp[ch] > 0)
            {
                reqcount--;
            }
            mpp[ch]--;

            while(reqcount == 0)
            {
                // ab shrink krdo window ko
                int currwindowsize = j-i+1;
                if(currwindowsize < minwindow)
                {
                    minwindow = currwindowsize;
                    start_i = i;
                }
                mpp[s[i]]++;
                if(mpp[s[i]] > 0)
                {
                    reqcount++;
                }
                
                i++;
            }
            j++;
        }
        return minwindow == INT_MAX ? "" : s.substr(start_i,minwindow);
        
    }
};