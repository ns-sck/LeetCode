class Solution {
public:
    int subarraysDivByK(vector<int>& v, int k) {
        ios::sync_with_stdio(0);
        map<int, int> mp;
        mp[0] =  1;
        for (int i = 0; i < v.size(); ++i) {
            if (i) v[i] += v[i-1];
            v[i] %= k;
            if (v[i] < 0) v[i] += k;
            ++mp[v[i]];
        }
        int ans = 0;
        for (auto p : mp) {
            ans += p.second*(p.second-1)/2;
        }
        return ans;
    }
};