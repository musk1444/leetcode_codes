class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {

        int n = nums.size();
        priority_queue<int, vector<int>, greater<>> minheap;

        for(auto num: nums)
        {
            minheap.push(num);
            while(minheap.size() > k)
            {
                minheap.pop();
            }
        }

        return minheap.top();

        
    }
};