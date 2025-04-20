class Solution {
public:
    int numRabbits(vector<int>& nums) {

        int n = nums.size();
        unordered_map<int,int> mpp;
        for(int i = 0; i<n; i++)
        {
            mpp[nums[i]]++;
        }
        int rabbits = 0;

        for(auto it:mpp)
        {
            int x = it.first;
            int count = it.second;

            int groupsize = x+1;
            int groups = ceil((double)count/groupsize);
            
            rabbits += groups * groupsize;

        }

        return rabbits;
        
    }
};