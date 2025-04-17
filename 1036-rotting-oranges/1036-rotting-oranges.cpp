class Solution {
public:
int dx[4] = {0,+1,0,-1};
int dy[4] = {+1,0,-1,0};

int m;
int n;


bool isvalid(int x, int y)
{
    return x >= 0 && y >= 0 && x<m && y<n;
}

    int orangesRotting(vector<vector<int>>& grid) {

        m = grid.size();
        n = grid[0].size();
        queue<pair<pair<int,int>, int>> q;

        int count = 0;

        vector<vector<int>> visited(m, vector<int>(n,0));

        for(int i = 0; i<m; i++)
        {
            for(int j = 0; j<n; j++)
            {
                if(grid[i][j] == 2 && visited[i][j] == 0)
                {
                    q.push({{i,j},0});
                }
            }
        }

        int maxtime = 0;

        while(!q.empty())
        {
            auto it = q.front();
            q.pop();

            int x = it.first.first;
            int y = it.first.second;
            int time = it.second;

            maxtime = max(time, maxtime);

            for(int i = 0; i<4; i++)
            {
                int newx = x + dx[i];
                int newy = y + dy[i];
                if(isvalid(newx,newy) && grid[newx][newy] == 1 && !visited[newx][newy])
                {
                    q.push({{newx,newy}, time+1});
                    visited[newx][newy] = 1;
                    grid[newx][newy] = 2;
                }
            }
        }

        for(int i = 0; i<m; i++)
        {
            for(int j = 0; j<n; j++)
            {
                if(grid[i][j] == 1 && !visited[i][j])
                {
                    return -1;
                }
            }
        }

        return maxtime;


        
    }
};