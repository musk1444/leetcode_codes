class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {

        int n = nums.size();
        vector<int> newarray(n+1,0);
        for(auto query: queries)
        {
            int start = query[0];
            int end = query[1];

            newarray[start] = newarray[start] + 1;
            if(end+1 < n)
            newarray[end+1] = newarray[end+1] - 1;
        }
        // now cumulative sum lelo newarray ka
        for(int i = 1; i<n; i++)
        {
            newarray[i] += newarray[i-1];
        }

        // now we check if the nums[i], all values are 1
        for(int i = 0; i<n; i++)
        {
            if(nums[i] > newarray[i])
            {
                return false;
            }
        }
        return true;
        
    }
};