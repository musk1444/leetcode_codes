class Solution {
public:
    string largestNumber(vector<int>& nums) {

        int n = nums.size();
        auto mycomp = [](int& a, int& b)
        {
            string s1 = to_string(a);
            string s2 = to_string(b);

            return s1+s2 > s2+s1;
        };

        sort(begin(nums), end(nums), mycomp);

        if(nums[0] == 0) return "0";

        string result = "";

        for(auto &num:nums)
        {
            result += to_string(num);
        }

        return result;
        
    }
};