class Solution {
public:
    int maxArea(vector<int>& height) {

        int n = height.size();
        int mostwater = 0;
        int i = 0;
        int j = n-1;

        while(i < j)
        {
            int width = j-i;
            int h = min(height[i],height[j]);
            int area = width*h; // we will calculate the area
            mostwater = max(mostwater,area);

            // make sure to decrease that pointer which has minimum height
            if(height[i] > height[j])
            {
                j--;
            }
            else
            {
                i++;
            }
        }

        return mostwater;
        
    }
};