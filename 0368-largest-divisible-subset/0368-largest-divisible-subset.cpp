class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {

        int n = nums.size();

        sort(nums.begin(), nums.end());
        vector<int> dp(n,1);
        vector<int> hash(n);

        int maxi = 1;
        int lastindex = 0;

        for(int index = 0; index<n; index++)
        {
            hash[index]= index;
            for(int prev = 0; prev<index;prev++)
            {
                if(nums[index] % nums[prev] == 0 && 1+dp[prev] > dp[index])
                {
                    dp[index] = 1+dp[prev];
                    hash[index] = prev;
                }
            }
            if(dp[index] > maxi)
            {
                maxi = dp[index];
                lastindex = index;
            }
        }

        vector<int> temp;
        temp.push_back(nums[lastindex]);
        while(hash[lastindex] != lastindex)
        {
            lastindex = hash[lastindex];
            temp.push_back(nums[lastindex]);
        }

        return temp;
        
    }
};