class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        if (n == 1) return {{"Q"}};
        if (n < 4) return {};
        vector<vector<string>> ans;
        string s; int m = n;
        while (m--) s += '.';
        vector<string> v(n, s);
        rec(ans, v, n, 0, 0, 0);
        return ans;
    }
    void rec(vector<vector<string>>& ans, vector<string> v, int n, int mask, int dg, int adg) {
        int r = __builtin_popcount(mask);
        if (r == n) {
            ans.push_back(v);
            return;
        }
        for (int i = 0; i < n; ++i) {
            int dgg = 1 << (r + (n-i-1));
            int adgg = 1 << (r + i);
            if (((1 << i) & mask) == 0 && (dgg & dg) == 0 && (adgg & adg) == 0) {
                v[r][i] = 'Q';
                rec(ans, v, n, (1 << i) | mask, dgg | dg, adgg | adg);
                v[r][i] = '.';
            }
        }
    }
};