class Solution {
public:

int dx[8] = {-1,-1,0,+1,+1,+1,0,-1};
int dy[8] = {0,+1,+1,+1,0,-1,-1,-1};

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        int n = grid.size();
        if(n == 1 && grid[0][0] == 0)
        {
            return 1;
        }
        if(grid[0][0] != 0 || grid[n-1][n-1] != 0)
        {
            return -1;
        }

        queue<pair<int,pair<int,int>>> q;
        vector<vector<int>> distance(n, vector<int>(n,INT_MAX));
        distance[0][0] = 1;
        q.push({1,{0,0}});

        while(!q.empty())
        {
            auto it = q.front();
            q.pop();

            int dist = it.first;
            int row = it.second.first;
            int col = it.second.second;

            for(int index = 0; index<8; index++)
            {
                int newrow = dx[index] + row;
                int newcol = dy[index] + col;

                if(newrow >= 0 && newrow<n && newcol>=0 && newcol<n
                 && (grid[newrow][newcol] == 0) && (dist+1 < distance[newrow][newcol]))
                {
                    distance[newrow][newcol] = dist + 1;
                    if(newrow == n-1 && newcol == n-1)
                    {
                        return distance[newrow][newcol];
                    }
                    q.push({dist+1,{newrow,newcol}});
                }
            }
        }
        return -1;
    }
};