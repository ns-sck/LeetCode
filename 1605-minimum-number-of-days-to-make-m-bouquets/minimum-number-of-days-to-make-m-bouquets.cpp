class Solution {
public:
    int minDays(vector<int>& b, int m, int k) {
        ios::sync_with_stdio(0);
        int N = b.size();
        if ((long long) m*k > N) return -1;
        bool ok = 0;
        int lo = 0, hi = 1e9+1;
        while (lo < hi) {
            int md = (lo+hi)>>1;
            int c = 0, t = 0;
            for (int i = 0; i < N; ++i) {
                if (md < b[i]) c = 0;
                if (md >= b[i]) ++c;
                if (c == k) {
                    ++t; c = 0;
                }
            }
            if (t >= m) {
                hi = md;
                ok = 1;
            } else lo = md+1;
        }
        if (ok) return lo;
        else return -1;
    }
};