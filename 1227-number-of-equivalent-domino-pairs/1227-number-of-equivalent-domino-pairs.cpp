class Solution {
public:

    int numEquivDominoPairs(vector<vector<int>>& dominoes) {

        for(auto &d: dominoes)
        {
            if(d[0] > d[1])
            {
                swap(d[1],d[0]);
            }
        }

        int n = dominoes.size();
        // pehle sort krdiya
        int count = 0;

        for(int i = 0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                if(dominoes[i][0] == dominoes[j][0] && dominoes[i][1] == dominoes[j][1])
                {
                    count++;
                }
            }
        }

        return count;

        
    }
};