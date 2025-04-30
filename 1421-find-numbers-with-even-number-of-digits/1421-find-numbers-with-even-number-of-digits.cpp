class Solution {
public:
bool isevendigit(int num)
{
    int digits = 0;
    while(num != 0)
    {
        digits++;
        num = num/10;
    }
    return (digits % 2 == 0);
}
    int findNumbers(vector<int>& nums) {

        int n = nums.size();
        int count = 0;
        for(int i = 0; i<n; i++)
        {
            if(isevendigit(nums[i]) == true)
            {
                count++;
            }
        }

        return count;
        
    }
};