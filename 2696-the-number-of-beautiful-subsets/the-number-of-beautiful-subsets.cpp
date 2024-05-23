class Solution {
public:
    int ans = -1;
    int beautifulSubsets(vector<int>& nums, int k) {
        ios::sync_with_stdio;
        dfs(nums, 0, 0, k);
        return ans; 
    }
    void dfs(vector<int>& v, int l, int mask, int k) {
        if (l == v.size()) {
            ++ans; return;
        }
        dfs(v, l+1, mask, k);
        bool b = 0;
        for (int i = 0; i < v.size(); ++i) if (((1 << i) & mask) && abs(v[i]-v[l]) == k) b = 1;
        if (!b) dfs(v, l+1, mask | (1 << l), k);
    }
};