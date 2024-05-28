class Solution {
public:
    int equalSubstring(string s, string t, int c) {
        // actually, no need for bs
        ios::sync_with_stdio;
        int sz = s.size();
        int prfx[sz+1];

        prfx[0] = 0; prfx[1] = abs(s[0] - t[0]);
        for (int i = 2; i <= sz; ++i)
            prfx[i] = abs(s[i-1] - t[i-1]) + prfx[i-1];

        int ans = 0;
        for (int i = 1; i <= sz; ++i) {
            int l = i, h = sz;
            while (l <= h) {
                int m = (l+h) / 2;
                if (prfx[m] - prfx[i-1] <= c) {
                    ans = max(ans, m-i+1);
                    l = m+1;
                } else h = m-1;
            }
        }
        return ans;
    }
};