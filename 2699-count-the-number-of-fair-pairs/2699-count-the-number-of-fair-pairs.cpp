class Solution {
public:
int lowerbound(int low, int high, int target, vector<int>& nums)
{
    int result = -1;
    while(low <= high)
    {
        int mid = low + (high - low)/2;
        if(nums[mid] >= target)
        {
            result = mid;
            high = mid-1;
        }
        else
        {
            low = mid+1;
        }
    }
    return result == -1 ? high + 1 : result; // return insertion point

}

int upperbound(int low, int high, int target, vector<int>& nums)
{
    int result = -1;
    while(low <= high)
    {
        int mid = low + (high - low)/2;
        if(nums[mid] > target)
        {
            result = mid;
            high = mid-1;
        }
        else
        {
            low = mid+1;
        }
    }
    return result == -1 ? high + 1 : result; // return insertion point
    
}
    long long countFairPairs(vector<int>& nums, int lower, int upper) {

        int n = nums.size();

        sort(begin(nums), end(nums));
        long long result = 0;

        for(int i = 0; i<n; i++)
        {
            // the first eement NOT LESS THAN lower - nums[i];
            // int index1 = lower_bound(nums.begin() + i + 1, nums.end(), lower-nums[i]) - nums.begin();
            int index1 = lowerbound(i+1, n-1,lower-nums[i], nums);

            // the first eement GREATER THAN upper - nums[i];
            // int index2 = upper_bound(nums.begin() + i + 1, nums.end(), upper-nums[i]) - nums.begin();
            int index2 = upperbound(i+1, n-1,upper-nums[i], nums);
            
            if(index1 != -1 && index2 != -1)
            {
                result += (index2 - index1);
            }
        }
        
        return result;
    }
};