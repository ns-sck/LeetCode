class Solution {
public:
    int countTriplets(vector<int>& arr) {
        ios::sync_with_stdio(0);
        int sz = arr.size(), ans = 0;
        vector<map<int, int>> a(sz+1);
        vector<map<int, int>> b(sz+1);
        
        for (int i = 0; i < sz; ++i) {
            int l = 0, r = 0;
            int xr = 0;
            while (r < sz && r-l < i) {
                xr ^= arr[r++];
            }
            xr ^= arr[r];
            ++b[l][xr];
            ++a[r][xr];
            
            while (++r < sz) {
                xr ^= arr[l++];
                xr ^= arr[r];
                ++b[l][xr];
                ++a[r][xr];
            }
        }

        for (int i = 1; i < sz; ++i) {
            map<int, int> mp;
            for (auto& [v, c]  : b[i]) {
                mp[v] += c;
            }
            for (auto& [v, c] : a[i-1]) {
                ans += mp[v] * c;
            }
        }
        return ans;
    }
};