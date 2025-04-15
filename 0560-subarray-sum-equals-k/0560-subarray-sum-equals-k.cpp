class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        unordered_map<int,int> prefix;
        prefix[0] = 1;
        int count = 0;
        int sum = 0;
        int n = nums.size();

        for(int i = 0;i<n; i++)
        {
            sum += nums[i];

            if(prefix.count(sum - k))
            {
                count += prefix[sum-k];
            }
            prefix[sum]++;
            
        }
        return count;
        
    }
};