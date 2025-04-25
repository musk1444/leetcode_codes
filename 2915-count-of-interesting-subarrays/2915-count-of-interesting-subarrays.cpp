class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        #define int long long int 
        int ans = 0;
        int n = nums.size();
        for(int i = 0; i < n;i++)
        {
            if (nums[i] % modulo == k)
            {
                nums[i] = 1;
            }
            else
            {
                nums[i] = 0;
            }
        }
        unordered_map <int, int> mp;
        int total = 0;
        for(int i = 0; i < n;i++)
        {
            total += nums[i];
            int mod_val = total % modulo;
            if (mod_val == k) ans++;
            int find = mod_val - k;
            if (find < 0)
            {
                find += modulo;
            }
            ans += mp[find];
            mp[mod_val]++;
        }
        return ans;
        #undef int 
    }
};