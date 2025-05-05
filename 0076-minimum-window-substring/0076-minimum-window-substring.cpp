class Solution {
public:
    string minWindow(string s, string t) {

        int n = s.length();
        int m = t.length();
        if(m > n)
        {
            return "";
        }

        unordered_map<char,int> mpp;
        for(auto ch:t)
        {
            mpp[ch]++;
        }

        int i = 0;
        int j = 0;
        int windowsize = INT_MAX;
        int reqcount = m; // the number of characters we need

        int startind = 0;

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
                // start shrinking the window
                int currwindowsize = j-i+1;
                if(currwindowsize < windowsize)
                {
                    startind = i;
                    windowsize = currwindowsize;
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

        return windowsize == INT_MAX ? "": s.substr(startind,windowsize);


        
    }
};