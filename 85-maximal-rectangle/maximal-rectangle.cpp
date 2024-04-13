class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();
        vector<vector<int>> g(r+2, vector<int>(c+2));
        int ans = 0;
        for (int i = 1; i <= r; ++i)
            for (int j = 1; j <= c; ++j) {
                if (matrix[i-1][j-1] == '1') {
                    g[i][j] = g[i-1][j] + 1;
                } else {
                    g[i][j] = 0;
                }
            }
        for (int i = 1; i <= r+1; ++i) {
            priority_queue<array<int,2>> pq;
            vector<int> l(c+2), r(c+2);
            for (int j = 1; j <= c+1; ++j) {
                while (pq.size() && pq.top()[0] > g[i][j]) {
                    int idx = pq.top()[1];
                    int h = pq.top()[0];
                    pq.pop();
                    int w = j - idx;
                    l[idx] = w*h;
                }
                pq.push({g[i][j], j});
            }
            for (int j = c+1; ~j; --j) {
                while (pq.size() && pq.top()[0] > g[i][j]) {
                    int idx = pq.top()[1];
                    int h = pq.top()[0];
                    pq.pop();
                    int w = idx - j;
                    r[idx] = w*h;
                }
                pq.push({g[i][j], j});
            }
            for (int j = 1; j <= c+1; ++j) {
                ans = max(ans, l[j] + r[j] - g[i][j]);
            }
        }
        return ans;
    }
};