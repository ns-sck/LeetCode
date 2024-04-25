class Solution {
public:
    int longestIdealString(string s, int k) {
        vector<int> a(26);
        int ans = 0;
        for (int i = 0; i < s.size(); ++i) {
            int d = s[i] - 'a';
            for (int i = 0; i <= k; ++i) {
                if (d-i >= 0)
                    a[d] = max({a[d], a[d-i]+1, 1});
                if (i && d+i < 26)
                    a[d] = max({a[d], a[d+i]+1, 1});
            }
            cout << s[i] << " and " << a[d] << '\n'; 
            ans = max(ans, a[d]);
        }
        return ans;
    }
};