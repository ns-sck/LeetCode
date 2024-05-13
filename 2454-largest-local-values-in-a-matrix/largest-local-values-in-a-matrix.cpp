class Solution {
public:
    int r[8] = {-1,-1,-1,0,0,1,1,1};
    int c[8] = {-1,0,1,-1,1,-1,0,1};
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> ans(n-2, vector<int>(n-2));
        for (int i = 1; i < n-1; ++i) {
            for (int k = 1; k < n-1; ++k) {
                int mxE = grid[i][k];
                for (int j = 0; j < 8; ++j) {
                    mxE = max(mxE, grid[i+r[j]][k+c[j]]);
                }
                ans[i-1][k-1] = mxE;
            }
        }
        return ans;
    }
};