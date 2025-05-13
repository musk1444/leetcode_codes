class Solution {
public:
    string pushDominoes(string d) {

        int n = d.length();
        vector<int> leftclosestr(n);
        vector<int> rightclosestl(n);

        // move form left to right
        // to find left closest R
        for(int i = 0; i<n; i++)
        {
            if(d[i] == 'R')
            {
                leftclosestr[i] = i; // R push starts from me 
            }
            else if(d[i] == '.')
            {
                leftclosestr[i] = i>0 ? leftclosestr[i-1] : -1;
            }
            else
            {
                leftclosestr[i] = -1;
            }
        }

        // move from right to left
        // to find closest right that has L
        for(int i = n-1; i>=0; i--)
        {
            if(d[i] == 'L')
            {
                rightclosestl[i] = i; // R push starts from me 
            }
            else if(d[i] == '.')
            {
                rightclosestl[i] = i<n-1 ? rightclosestl[i+1] : -1;
            }
            else
            {
                rightclosestl[i] = -1;
            }
        }

        string result(n,' ');
        for(int i = 0; i<n; i++)
        {
            int distleftr = abs(i-leftclosestr[i]);
            int distrightl = abs(i-rightclosestl[i]);

            if(leftclosestr[i] == rightclosestl[i])
            {
                result[i] = '.';
            }
            else if(rightclosestl[i] == -1)
            {
                result[i] = 'R';
            }
            else if(leftclosestr[i] == -1)
            {
                result[i] = 'L';
            }
            else if(distleftr == distrightl)
            {
                result[i] = '.'; 
            }
            else
            {
                result[i] = distrightl < distleftr ? 'L' : 'R';
            }
        }
        return result;
        
    }
};