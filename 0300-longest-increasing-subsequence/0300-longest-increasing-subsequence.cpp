class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {

        int n = nums.size();
        vector<int> dp(n,1);
        vector<int> hash(n);

        int maxi = 1;
        int lastindex = 0;

        for(int index = 0; index < n;index++)
        {
            hash[index] = index;
            for(int prev = 0; prev<=index - 1; prev++)
            {
                if(nums[prev] < nums[index] &&  (1 + dp[prev] > dp[index]))
                {
                    // agar humara prev chota h abhi wale element se, to humara subsequence ban skta h
                    dp[index] = 1 + dp[prev];
                    hash[index] = prev;
                }
            }

            if(dp[index] > maxi)
            {
                maxi = dp[index];
                lastindex = index;
            }
        }
        vector<int> temp;
        temp.push_back(nums[lastindex]);
        while(hash[lastindex] != lastindex)
        {
            lastindex = hash[lastindex];
            temp.push_back(nums[lastindex]);
        }

        reverse(begin(temp), end(temp));
        for(auto it: temp)
        {
            cout << it << " ";
        }

        return maxi;
        
    }
};