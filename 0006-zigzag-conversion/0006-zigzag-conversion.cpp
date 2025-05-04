class Solution {
public:
    string convert(string s, int numRows) {

        int nr = numRows;
        if(nr == 1)
        {
            return s;
        }
        vector<string> rows(nr);
        bool isdown = true;

        for(int i = 0, j = 0; i<s.size(); i++)
        {
            rows[j].push_back(s[i]);
            if(isdown)
            {
                if(j == nr-1)
                {
                    j--;
                    isdown = false;
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
                    isdown = true;
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