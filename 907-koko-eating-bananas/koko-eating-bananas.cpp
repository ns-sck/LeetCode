class Solution {
public:
    int minEatingSpeed(vector<int>& p, int h) {
        ios::sync_with_stdio(0);
        sort(p.begin(), p.end());
        int N = p.size();
        int lo = 1, hi = p[N-1];
        while (lo < hi) {
            int mi = (lo+hi)>>1;
            int c = 0;
            for (int i = 0; i < N; ++i) {
                int x = p[i] / mi;
                c += x + (p[i] % mi != 0) ;
            }
            if (c > h) lo = mi+1;
            else hi = mi;
        }
        return lo;
    }
};