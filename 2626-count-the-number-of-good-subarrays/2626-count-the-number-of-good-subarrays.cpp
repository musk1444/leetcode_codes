class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        
        int n = nums.size();
        int i = 0;
        int j = 0;
        long long pairs = 0;
        long long result = 0;

        unordered_map<int,int> mpp;
        while(j < n)
        {
            pairs += mpp[nums[j]];
            mpp[nums[j]]++;

            while(pairs >= k)
            {
                mpp[nums[i]]--;
                // decreease the frequency
                
                pairs -= mpp[nums[i]];
                // decrease it from pairs as well
                result += (n-j);
                i++;
            }
            j++;

        }
        return result;
    }
};