class Solution { // 180 ms, faster than 33.33%
public:
    int memo[1000][1024] = {};
    vector<int> neiMemo[1024] = {};
    int m, n, MOD = 1e9 + 7;
    int colorTheGrid(int m, int n) {
        this->m = m; this->n = n;
        return dp(0, 0);
    }
    int dp(int c, int prevColMask) {
        if (c == n) return 1; // Found a valid way
        if (memo[c][prevColMask]) return memo[c][prevColMask];
        int ans = 0;
        for (int nei : neighbors(prevColMask))
            ans = (ans + dp(c + 1, nei)) % MOD;
        return memo[c][prevColMask] = ans;
    }
    vector<int> neighbors(int prevColMask) { // Generate all possible columns we can draw, if the previous col is `prevColMask`
        if (!neiMemo[prevColMask].empty()) return neiMemo[prevColMask];
        dfs(0, prevColMask, 0, neiMemo[prevColMask]);
        return neiMemo[prevColMask];
    }
    void dfs(int r, int prevColMask, int curColMask, vector<int>& out) {
        if (r == m) { // Filled full color for this column
            out.push_back(curColMask);
            return;
        }
        for (int i = 1; i <= 3; ++i) // Try colors i in [1=RED, 2=GREEN, 3=BLUE]
            if (getColor(prevColMask, r) != i && (r == 0 || getColor(curColMask, r-1) != i))
                dfs(r + 1, prevColMask, setColor(curColMask, r, i), out);
    }
    int getColor(int mask, int pos) { // Get color of the `mask` at `pos`, use 2 bits to store a color
        return (mask >> (2 * pos)) & 3;
    }
    int setColor(int mask, int pos, int color) { // Set `color` to the `mask` at `pos`, use 2 bits to store a color
        return mask | (color << (2 * pos));
    }
};