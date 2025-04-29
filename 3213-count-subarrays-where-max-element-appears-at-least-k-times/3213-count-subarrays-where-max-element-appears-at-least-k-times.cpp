class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {

        int n = nums.size();
        long long result = 0;
        // pehle max element nikalo poore array me se
        int maxelem = *max_element(nums.begin(), nums.end());
        long long countmax = 0;

        int i = 0;
        int j = 0;
        while(j<n)
        {
            if(nums[j] == maxelem)
            {
                countmax++;
            }
            while(countmax >= k)
            {
                // ab jab tak hume maxelem ka count k se bda milta h, aagebdhte jaai
                result += (n-j);
                if(nums[i] == maxelem)
                {
                    countmax--;
                } 
                i++;
            }
            j++;
        }

        return result;
        
    }
};