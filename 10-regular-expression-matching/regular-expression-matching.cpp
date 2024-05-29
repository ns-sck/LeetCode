class Solution {
public:
    bool isMatch(string s, string p) {
        ios::sync_with_stdio;
        int n = s.size(), m = p.size();
        vector<vector<bool>> dp(n+1, vector<bool>(m+1));
        dp[0][0] = 1;
        
        for (int i = 0; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                bool b = 0;
                if (p[j-1] == '*') {
                    b |= j>1 && dp[i][j-2];
                    b |= i && (dp[i-1][j] && (s[i-1] == p[j-2] || p[j-2] == '.'));
                } else {
                    b |= i && ((dp[i-1][j-1]) && (s[i-1] == p[j-1] || p[j-1] == '.'));
                }
                dp[i][j] = b; 
            }
        }
        return dp[n][m];
    }
};