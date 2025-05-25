class Solution {
public:

int n;

int find(vector<int>& tops, vector<int>& bottoms, int& value)
{
    int swap_top = 0;
    int swap_bottom = 0;

    for(int i = 0; i<n; i++)
    {
        if(tops[i] != value && bottoms[i] != value)
        {
            return -1;
        } 
        else if(tops[i] != value)
        {
            swap_top++;
        }
        else if(bottoms[i] != value)
        {
            swap_bottom++;
        }
    }

    return min(swap_top,swap_bottom);

}
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {

        n = tops.size();
        // we simply check if we can make value for every top and bottom
        int result = INT_MAX;

        for(int val = 1; val <= 6; val++)
        {
            int steps = find(tops,bottoms,val);
            if(steps != -1)
            {
                result = min(result,steps);
            } 
        }
        return result == INT_MAX ? -1: result;


        
    }
};