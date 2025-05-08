class Solution {
public:
    int minTimeToReach(vector<vector<int>>& t) {
        int n = t.size(), m = t[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(2, INT_MAX)));

        using State = tuple<int, int, int>;
        using PQNode = pair<int, State>;
        priority_queue<PQNode, vector<PQNode>, greater<>> pq;

        dp[0][0][0] = 0;
        pq.push({0, {0, 0, 0}});

        vector<pair<int,int>> dir{{-1,0},{1,0},{0,-1},{0,1}};

        while (!pq.empty()) {
            auto [time, state] = pq.top(); pq.pop();
            auto [x, y, parity] = state;

            if (dp[x][y][parity] < time) continue;

            for (auto [dx, dy] : dir) {
                int nx = x + dx, ny = y + dy;
                if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;

                int wait_time = max(time, t[nx][ny]);
                int next_parity = 1 - parity;
                int next_time = wait_time + 1 + parity;

                if (nx == n - 1 && ny == m - 1)
                    return next_time;

                if (dp[nx][ny][next_parity] <= next_time) continue;

                dp[nx][ny][next_parity] = next_time;
                pq.push({next_time, {nx, ny, next_parity}});
            }
        }

        return -1;
    }
};