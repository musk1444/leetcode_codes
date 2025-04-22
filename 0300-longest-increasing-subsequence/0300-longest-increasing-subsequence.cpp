class Solution {
public:
    int n;

    int solve(int index, int previndex, vector<int>& nums,
              vector<vector<int>>& dp) {
        if (index >= n) {
            return 0;
        }
        if (dp[index][previndex + 1] != -1) {
            return dp[index][previndex + 1];
        }

        int len = INT_MIN;
        int not_take = 0 + solve(index + 1, previndex, nums, dp);
        int take = 0;
        if (previndex == -1 || nums[index] > nums[previndex]) {
            take = 1 + solve(index + 1, index, nums, dp);
        }

        return dp[index][previndex + 1] = len = max(take, not_take);
    }
    int lengthOfLIS(vector<int>& nums) {

        n = nums.size();

        // vector<vector<int>> dp(n, vector<int>(n+1,-1));
        // we have made our previndex shifted by 1 place ahead, to actually
        // cater the -1

        // return solve(0,-1,nums, dp);
        // we have {index, previndex}
        // in the beginning we have -1 as our previndex

        // vector<vector<int>> dp(n+1, vector<int>(n + 1, 0));


        vector<int> after(n + 1, 0);
        vector<int> curr(n + 1, 0);

        for (int index = n - 1; index >= 0; index--) {
            for (int previndex = index - 1; previndex >= -1; previndex--) {

                int len = INT_MIN;
                int not_take = 0 + after[previndex + 1];
                int take = 0;
                if (previndex == -1 || nums[index] > nums[previndex]) {
                    take = 1 + after[index + 1];
                }

                curr[previndex + 1] = len = max(take, not_take);
            }
            after = curr;
        }

        return after[-1 +1];
    }
};