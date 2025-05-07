class Solution {
public:
    int maxProfit(vector<int>& nums) {

        int n = nums.size();
        int mini = nums[0];
        int profit = INT_MIN;

        for(int i = 0; i<n; i++)
        {
            int cost = nums[i] - mini;
            profit = max(profit,cost);
            mini = min(mini,nums[i]);
        }
        return profit;
        
    }
};