class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {

        int n = nums.size();
        sort(begin(nums), end(nums));

        return nums[n-k];
        
    }
};