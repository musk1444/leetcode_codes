class Solution {
public:
    long long countGood(vector<int>& nums, int k) {

        int n = nums.size();
        
        unordered_map<int,int> mpp;
        long long pairs = 0;
        long long count = 0;

        int i = 0;
        int j = 0;
        while(j < n)
        {
            pairs += mpp[nums[j]]; // we keep adding the number of time swe have prevoiosuly seen nums[j];
            mpp[nums[j]]++;

            while(pairs >= k)
            {
                // jab tak hume ans mil rh ah humara
                count += (n-j);
                // we need to shrink the window as well
                mpp[nums[i]]--;
                pairs -= mpp[nums[i]];
                i++;
            }

            j++;
        }

        return count;

        
    }
};