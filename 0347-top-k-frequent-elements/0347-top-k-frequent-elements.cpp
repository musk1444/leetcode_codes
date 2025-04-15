class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;

        int n = nums.size();
        for(int i = 0; i<n; i++)
        {
            mpp[nums[i]]++;
        }

        priority_queue<pair<int,int>, vector<pair<int,int>> , greater<>> minheap;
        for(auto it: mpp)
        {
            minheap.push({it.second, it.first});
            if(minheap.size() > k)
            {
                minheap.pop();
            }
        }
        vector<int> res;
        while(!minheap.empty())
        {
            res.push_back(minheap.top().second);
            minheap.pop();
        }

        return res;
        
    }
};