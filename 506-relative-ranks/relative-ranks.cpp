class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& s) {
        ios::sync_with_stdio;
        int sz = s.size();
        vector<array<int, 2>> v;
        for (int i = 0; i < sz; ++i) {
            v.push_back({s[i], i});
        }
        sort(v.rbegin(), v.rend());
        vector<string> ans(sz);
        for (int i = 0; i < sz; ++i) {
            int idx = v[i][1];
            if (i == 0) ans[idx] = "Gold Medal";
            else if (i == 1) ans[idx] = "Silver Medal";
            else if (i == 2) ans[idx] = "Bronze Medal";
            else ans[idx] = to_string(i+1);
        }
        return ans;
    }
};