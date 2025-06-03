class Solution {
public:
       int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int res = 0, i;
        queue<int> q;
        for (int i : initialBoxes)
            if ((status[i] += 5000) > 5000)
                q.push(i);
        while (!q.empty()) {
            i = q.front(), q.pop();
            res += candies[i];
            for (int j : keys[i])
                if ((status[j] += 5) == 5005)
                    q.push(j);
            for (int j : containedBoxes[i])
                if ((status[j] += 5000) > 5000)
                    q.push(j);
        }
        return res;
    }
};