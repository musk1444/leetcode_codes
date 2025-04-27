class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        
        long long ans = 0;
        int minpos = -1;
        int maxpos = -1;
        int culprit = -1;
        int n = nums.size();

        for(int i = 0; i<n; i++)
        {
            if(nums[i] < minK || nums[i] > maxK)
            {
                culprit = i;
            }
            if(nums[i] == minK)
            {
                minpos = i;
            }
            if(nums[i] == maxK)
            {
                maxpos = i;
            }

            long long smaller = min(minpos, maxpos);
            int temp = smaller - culprit;

            ans += temp <= 0? 0 : temp;
        }

        return ans;
    }
};