class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {

        int sourcecolor = image[sr][sc];
        int m = image.size();
        int n = image[0].size();

        int dx[4] = {0,+1,0,-1};
        int dy[4] = {+1,0,-1,0};
        queue<pair<int,int>> q;
        q.push({sr,sc});
        image[sr][sc] = color;

        vector<vector<int>> vis(m, vector<int>(n,0));
        vis[sr][sc] = 1;

        while(!q.empty())
        {
            auto it = q.front();
            q.pop();

            int x = it.first;
            int y = it.second;
            for(int i = 0; i<4; i++)
            {
                int newx = x+dx[i];
                int newy = y+dy[i];

                if(newx >= 0 && newy >= 0 && newx < m && newy<n 
                && image[newx][newy] == sourcecolor && !vis[newx][newy])
                {
                    image[newx][newy] = color;
                    vis[newx][newy] = 1;
                    q.push({newx,newy});
                }
            }
        }
    return image;
        
    }
};