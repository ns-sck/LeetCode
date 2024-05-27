#define ll long long
class Solution {
public:

    const ll MOD = 1e9+7;
    ll dp[100001][2][3];

    int checkRecord(int n) {
        fill(&dp[0][0][0], &dp[0][0][0] + sizeof(dp) / sizeof(ll), 0);
        dp[0][0][0] = dp[0][1][0] = dp[0][0][1] = 1;
        for (int i = 1; i < n; ++i) {
            dp[i][0][0] = (dp[i][0][0] + dp[i-1][0][0] + dp[i-1][0][1] + dp[i-1][0][2]) % MOD;
            dp[i][0][1] = (dp[i][0][1] + dp[i-1][0][0]) % MOD;
            dp[i][0][2] = (dp[i][0][2] + dp[i-1][0][1]) % MOD;
            dp[i][1][0] = (dp[i][1][0] + dp[i-1][0][0] + dp[i-1][0][1] + dp[i-1][0][2]
                         + dp[i-1][1][0] + dp[i-1][1][1] + dp[i-1][1][2]) % MOD;
            dp[i][1][1] = (dp[i][1][1] + dp[i-1][1][0]) % MOD;
            dp[i][1][2] = (dp[i][1][2] + dp[i-1][1][1]) % MOD;
        }
        return (dp[n-1][0][0] + dp[n-1][0][1] + dp[n-1][0][2] + dp[n-1][1][0] + dp[n-1][1][1] + dp[n-1][1][2]) % MOD;
    }
};