class Solution {
public:
    string convert(string s, int numRows) {

        int n = numRows;
        if(n == 1)
        {
            return s;
        }
        vector<string> rows(n); // we create a vector of string of size numrows for
        // storing each row

        bool down = true;

        for(int i = 0,j=0; i<s.size(); i++)
        {
            rows[j].push_back(s[i]);
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
                if(j == 0)
                {
                    j++;
                    down = true;
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