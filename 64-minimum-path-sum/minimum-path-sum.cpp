class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        vector<vector<int>> dp(r+1, vector<int>(c+1, 1e9));
        dp[1][1] = grid[0][0];
        for (int i = 1; i <= r; ++i)
            for (int j = 1; j <= c; ++j) {
                dp[i][j] = min(dp[i][j], min(dp[i-1][j], dp[i][j-1]) + grid[i-1][j-1]);
            }
        return dp[r][c];
    }
};