class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        
        // pehle coutn of distinct integers nikaal lo
        set<int> numset(nums.begin(), nums.end());
        int count = numset.size();
        int n = nums.size();

        int i = 0;
        int j = 0;
        unordered_map<int,int> mpp;

        int result = 0;
        while(j<n)
        {
            // we will keep adding the freqency into our map
            mpp[nums[j]]++;

            while(mpp.size() == count)
            {
                // jab tak number of distinct elements count jitne h subarray me
                result += (n-j);
                mpp[nums[i]]--;
                if(mpp[nums[i]] == 0)
                {
                    mpp.erase(nums[i]);
                }
                i++;
            }
            j++;
        }

        return result;
    }
};