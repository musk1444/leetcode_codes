class Solution {
public:
    string countAndSay(int n) {

        if(n == 1) return "1";
        if(n == 2) return "11";

        string current = "11";
        for(int i = 3; i<=n; i++)
        {
            string next = "";
            int count = 1;

            for(int j = 1;j<current.size();j++)
            {
                if(current[j] == current[j-1])
                {
                    count++;
                }
                else
                {
                    next+= to_string(count) + current[j-1];
                    count = 1;
                }
            }

            next = next + to_string(count) + current.back();
            current = next;

        }
        return current;
    }
};
        
