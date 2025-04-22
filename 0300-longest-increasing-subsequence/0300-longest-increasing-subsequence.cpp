class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {

        int n = nums.size();
        vector<int> dp(n,1);

        for(int index = 0; index < n;index++)
        {
            for(int prev = 0; prev<=index - 1; prev++)
            {
                if(nums[prev] < nums[index])
                {
                    // agar humara prev chota h abhi wale element se, to humara subsequence ban skta h
                    dp[index] = max(dp[index], 1 + dp[prev]);
                }
            }
        }

        return *max_element(begin(dp), end(dp));
        
    }
};