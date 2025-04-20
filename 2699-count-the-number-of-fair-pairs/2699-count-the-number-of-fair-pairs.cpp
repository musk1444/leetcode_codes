class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {

        int n = nums.size();

        sort(begin(nums), end(nums));
        long long result = 0;

        for(int i = 0; i<n; i++)
        {
            int index1 = lower_bound(nums.begin() + i + 1, nums.end(), lower-nums[i]) - nums.begin();
            int x = index1 - 1 - i;
            // the first eement NOT LESS THAN lower - nums[i];

            int index2 = upper_bound(nums.begin() + i + 1, nums.end(), upper-nums[i]) - nums.begin();
            int y = index2 - 1 - i;
            // the first eement GREATER THAN upper - nums[i];


            result += (y-x);
        }
        
        return result;
    }
};