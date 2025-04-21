class Solution {
public:

int n;

int solve(int index, int previndex, vector<int>& nums, vector<vector<int>>& dp)
{
    if(index >= n)
    {
        return 0;
    }
    if(dp[index][previndex + 1] != -1)
    {
        return dp[index][previndex+1];
    }

    int len = INT_MIN;
    int not_take = 0 + solve(index+1, previndex,nums,dp);
    int take = 0;
    if(previndex == -1 || nums[index] > nums[previndex])
    {
        take = 1 + solve(index+1,index, nums,dp);
    }
  
    return dp[index][previndex+1] = len = max(take, not_take);
}
    int lengthOfLIS(vector<int>& nums) {

        n = nums.size();

        vector<vector<int>> dp(n, vector<int>(n+1,-1));
        // we have made our previndex shifted by 1 place ahead, to actually cater the -1
        
        return solve(0,-1,nums, dp);
        // we have {index, previndex}
        // in the beginning we have -1 as our previndex
        
    }
};