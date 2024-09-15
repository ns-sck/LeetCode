class Solution {
public:
    int findTheLongestSubstring(string S) {
        ios::sync_with_stdio(0);

        int N = S.size();

        map<int, int> mp;
        int mask = 0, ans = 0;
        mp[0] = -1;

        for (int i = 0; i < N; ++i) {
            int c = S[i] - 'a';
            if (c ^ 0 && c ^ 4 && c ^ 8 && c ^ 14 && c ^ 20) {
                ans = max(ans, i - mp[mask]);
            } else {
                mask ^= (1 << c);
                if (mp.count(mask)) {
                    ans = max(ans, i - mp[mask]);
                } else mp[mask] = i;
            }
        }

        return ans;
    }
};