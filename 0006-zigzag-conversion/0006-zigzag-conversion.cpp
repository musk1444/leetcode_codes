class Solution {
public:
    string convert(string s, int numRows) {

        int n = numRows;
        if(n == 1)
        {
            return s;
        }

        vector<string> rows(n);
        bool down = true;

        for(int i = 0, j = 0; i<s.size(); i++)
        {
            rows[j].push_back(s[i]); // j ko push back krdo uss row me
            if(down)
            {
                if(j == n-1)
                {
                    down = false;
                    j--;
                }
                else
                {
                    j++;
                }
            }
            else
            {
                // agar down true nai h to
                if( j == 0)
                {
                    down = true;
                    j++;
                }
                else
                {
                    j--;
                }
            }
        }

        string ans = "";
        for(int i = 0; i<rows.size(); i++)
        {
            ans += rows[i];
        }

        return ans;
        
    }
};