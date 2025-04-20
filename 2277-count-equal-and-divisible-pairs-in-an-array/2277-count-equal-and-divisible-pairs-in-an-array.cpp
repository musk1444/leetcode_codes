class Solution {
public:
    int countPairs(vector<int>& nums, int k) {

        int n = nums.size();
        int count = 0;

        unordered_map<int, vector<int>> indicesmap;
        for(int i = 0; i<n; i++)
        {
            indicesmap[nums[i]].push_back(i);
        }
        // k = 26;
        // = {1,2,3,4,6,18,12}
        unordered_set<int> div;
        for(int factor = 1; factor*factor <= k; factor++)
        {
            if(k%factor == 0)
            {
                div.insert(factor);
                div.insert(k/factor);
            }
        }

        for(auto &[num, indices]: indicesmap)
        {
            unordered_map<int,int> factorsmap;
            for(auto i:indices)
            {
                int GCD = gcd(i,k);
                int j = k/GCD;
                
                count += factorsmap[j];
                for(int f: div)
                {
                    if(i%f == 0)
                    {
                        factorsmap[f]++;
                    }
                }

            }

        }
        return count;
        
    }
};