class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int n = nums.size();
        int maxending = nums[0];
        int result = nums[0];

        for(int i = 1; i<n; i++)
        {
            maxending = max(maxending + nums[i], nums[i]);
            result = max(result,maxending);
        }
        return result;
        
    }
};