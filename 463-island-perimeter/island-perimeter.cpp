class Solution {
public:
    int islandPerimeter(vector<vector<int>>& g) {
        int r = g.size();
        int c = g[0].size();
        int ans = 0;
        for (int i = 0; i < r; ++i)
            for (int j = 0; j < c; ++j) {
                if (g[i][j]) {
                    ans += (i == 0 || g[i-1][j] == 0);
                    ans += (j == 0 || g[i][j-1] == 0);
                    ans += (i == r-1 || g[i+1][j] == 0);
                    ans += (j == c-1 || g[i][j+1] == 0);
                }
            }
        return ans;
    }
};