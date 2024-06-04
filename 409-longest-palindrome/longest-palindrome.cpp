class Solution {
public:
    int longestPalindrome(string s) {
        ios::sync_with_stdio;
        vector<int> a(58);
        for (int i = 0; i < s.size(); ++i) ++a[s[i]-'A'];
        int ans = 0;
        bool b = 0;
        for (int i = 0; i < 58; ++i) {
            if (a[i]%2) {
                b = 1;
                ans += a[i]-1;
            } else ans += a[i];
        }
        return ans+b;
    }
};