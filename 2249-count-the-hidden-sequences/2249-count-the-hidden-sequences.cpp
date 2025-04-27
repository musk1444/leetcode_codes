class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {

        int minval = 0;
        int maxval = 0;
        int curr = 0;

        for(auto d:differences)
        {
            curr = curr+d;
            // we are finding the new val

            minval = min(minval, curr);
            maxval = max(maxval, curr);

            if(upper - maxval - (lower - minval) + 1 <= 0)
            {
                return 0;
            }
        }
        return upper - maxval - (lower - minval) + 1;

    }
};