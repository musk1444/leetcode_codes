class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {

        int n = nums.size();
        unordered_map<int,int> mpp;
        
        // mpp[0] = 1; as we have already seen the remainder 0
        int sum = 0;
        mpp[0] = 1;
        int result = 0;

        for(int i = 0; i<n; i++)
        {
            sum += nums[i];

            int remainder = sum%k;
            if(remainder < 0)
            {
                remainder += k; // to avod the edge case fo rnegative rem
            }
            // now we will check if we have previosly seen this remainder
            if(mpp.find(remainder) != mpp.end())
            {
                result += mpp[remainder];
            }
            mpp[remainder]++;
        }
        
        return result;
    }
};