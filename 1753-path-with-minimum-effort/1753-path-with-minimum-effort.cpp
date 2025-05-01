class Solution {
public:
typedef pair<int, pair<int, int>> P;

    int minimumEffortPath(vector<vector<int>>& heights) {

        int n = heights.size();
        int m = heights[0].size();

        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({0,{0,0}});
        vector<vector<int>> distance(n, vector<int>(m,INT_MAX));
        distance[0][0] = 0;

        int dx[4] = {-1,0,+1,0};
        int dy[4] = {0,+1,0,-1};

        while(!pq.empty())
        {
            auto it = pq.top();
            pq.pop();

            int dist = it.first;
            int row = it.second.first;
            int col = it.second.second;

            if(row == n-1 && col == m-1)
            {
                return dist;
            }

            for(int index = 0; index<4; index++)
            {
                int newrow = dx[index] + row;
                int newcol = dy[index] + col;
                if(newrow >= 0 && newcol >= 0 && newrow<n && newcol<m)
                {
                    int neweffort = max(dist, abs(heights[newrow][newcol] - heights[row][col]));
                    if(neweffort < distance[newrow][newcol])
                    {
                        distance[newrow][newcol] = neweffort;
                        pq.push({neweffort,{newrow,newcol}});
                    }
                }
            }
        }
        return 0;

        
    }
};