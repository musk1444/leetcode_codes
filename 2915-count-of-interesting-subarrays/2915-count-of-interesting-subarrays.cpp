class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int m, int k) {
        
        int n = nums.size();
        for(int i = 0; i<n; i++)
        {
            if(nums[i] %m == k)
            {
                nums[i] = 1;
                // to make sure that elements that are divisible get marked as 1
            }
            else
            {
                nums[i] = 0;
            }
        }

        long long sum = 0;
        long long result = 0;
        unordered_map<int, long long> mpp;
        mpp[0] = 1;
        
        for(int i = 0; i<n; i++)
        {
            sum += nums[i];
            int r1 = sum%m;
            // we get the forst remainder

            int r2 = (r1 - k + m)%m;
            result += mpp[r2];

            mpp[r1]++;

        }

        return result;
    }
};