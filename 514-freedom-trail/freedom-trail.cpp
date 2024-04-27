class Solution {
public:
    int findRotateSteps(string ring, string key) {
        ios::sync_with_stdio;
        vector<vector<int>> t(26);
        int sz = ring.size();
        for (int i = 0; i < ring.size(); ++i) {
            int c = ring[i] - 'a';
            t[c].push_back(i);
        }
        vector<vector<int>> dp(sz, vector<int>(key.size(), -1));
        vector<int> dp2(sz, -1);
        queue<array<int, 3>> q;
        for (int i = 0; i < sz; ++i) {
            if (ring[i] == key[0]) {
                q.push({i, 0, min(i, sz-i)});
            }
        }
        int ans = 1e9;
        // array<int, 2> dp3 = {0, 1e9};
        while (q.size()) {
            auto [idx_r, idx_k, c] = q.front();
            q.pop();
            if (idx_k == key.size()-1) {
                ans = min(ans, c);
                continue;
            }
            int next = key[idx_k+1] - 'a';
            for (auto i : t[next]) {
                int dff = min(abs(idx_r-i), sz-(abs(idx_r-i)));
                if ((dp[i][idx_k+1] == -1 || dp[i][idx_k+1] > c+dff) && dp2[i] <= idx_k+1) {
                    q.push({i, idx_k+1, c+dff});
                    dp[i][idx_k+1] = c+dff;
                    dp2[i] = idx_k+1;
                }
            }
        }
        return ans + key.size();
    }
};