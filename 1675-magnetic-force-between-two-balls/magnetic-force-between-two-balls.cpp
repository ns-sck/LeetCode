class Solution {
public:
    int maxDistance(vector<int>& p, int m) {
        ios::sync_with_stdio(0);

        sort(p.begin(), p.end());
        int N = p.size();
        
        int lo = 1, hi =(p[N-1]-p[0])/(m-1)+1;
        while (lo < hi) {
            int md = (lo+hi)>>1;
            int c = 1, l = p[0];
            for (int i = 1; i < N; ++i) {
                if (p[i]-l >= md) {
                    ++c;
                    l = p[i];
                }
            }
            if (c >= m) lo = md+1;
            else hi = md;
        }
        return --lo;
    }
};