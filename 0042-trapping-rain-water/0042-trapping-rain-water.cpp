class Solution {
public:
    int trap(vector<int>& height) {

        int n = height.size();
        vector<int> leftmax(n);
        leftmax[0] = height[0];

        vector<int> rightmax(n);
        rightmax[n-1] = height[n-1];

        for(int i = 1; i<n; i++)
        {
            leftmax[i] = max(leftmax[i-1], height[i]);
        }
        for(int i = n-2; i>=0; i--)
        {
            rightmax[i] = max(rightmax[i+1], height[i]);
        }
        // we have the left and right maxes now, we can simply iterate over every element
        int totalwater = 0;

        for(int i = 0; i<n; i++)
        {
            totalwater += min(leftmax[i], rightmax[i]) - height[i];
        }

        return totalwater;
        
    }
};