class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {

        int count = 0;
        int n = nums.size();
        set<int> numset(nums.begin(),nums.end());

        return (numset.size() < nums.size());
    }
};