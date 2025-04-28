class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {

        long long count = 0;
        int n = nums.size();
        long long sum = 0;

        int i = 0;
        int j = 0;
        while(j < n)
        {
            sum += nums[j];
            // we will keep shrinking until our score is greater than or equal to k
            while(i<=j && sum * (j-i+1) >= k)
            {
                // decrease the sum
                sum -= nums[i];
                i++;
            }
            count += (j-i+1);
            j++;
        }

        return count;
        
    }
};