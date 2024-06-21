class Solution {
public:
    int maxSatisfied(vector<int>& c, vector<int>& g, int M) {
        ios::sync_with_stdio(0);
        int N = c.size();

        int t = 0, w = 0, wm = 0;
        for (int i = 0; i < N; ++i) {
            if (!g[i]) t += c[i];
            if (i < M && g[i]) w += c[i];
        }
        wm = w;
        for (int i = M; i < N; ++i) {
            if (g[i-M]) w -= c[i-M];
            if (g[i]) w += c[i];
            wm = max(w, wm);
        }
        return t+wm;
    }
};