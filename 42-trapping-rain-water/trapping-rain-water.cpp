class Solution {
public:
    int trap(vector<int>& h) {
        int ans = 0, t = 0;
        stack<tuple<int,int,int>> st;
        int i = 0, j = h.size()-1;
        cout << i << j;
        while (i < h.size() && h[i] == 0) ++i;
        while (~j && h[j] == 0) --j;
        for (; i <= j; ++i) {
            while (st.size()) {
                auto [idx, hg, prfx] = st.top();
                if (hg <= h[i]) {
                    st.pop();
                    int diff = t-prfx;
                    int fill = hg * (i-idx-1) - diff;
                    ans += fill;
                    t += fill;
                } else {
                    int diff = t-prfx;
                    int fill = h[i] * (i-idx-1) - diff;
                    ans += fill;
                    t += fill;
                    break;
                }
            }
            t += h[i];
            st.push({i, h[i], t});
        }
        return ans;
    }
};  