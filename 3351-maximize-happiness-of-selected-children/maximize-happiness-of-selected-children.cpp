class Solution {
public:
    long long maximumHappinessSum(vector<int>& h, int k) {
        long long ans = 0, c = 0;
        sort(h.begin(), h.end());
        for (int i = h.size()-1; ~i; --i) {
            if (c == k) return ans;
            long long x = max(h[i]-c, 0LL);
            ans += x; ++c;
        }
        return ans;
    }
};