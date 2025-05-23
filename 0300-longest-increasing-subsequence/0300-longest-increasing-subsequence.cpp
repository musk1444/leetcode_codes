class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {

        int n = nums.size();
        vector<int> temp;
        temp.push_back(nums[0]);

        for(int i = 1;i<n; i++)
        {
            if(temp.back() < nums[i])
            {
                temp.push_back(nums[i]);
            }
            else
            {
                // we find where should we insert our element
                int index = lower_bound(temp.begin(), temp.end(), nums[i]) - temp.begin();
                temp[index] = nums[i];
            }
        }

        return temp.size();
        
    }
};