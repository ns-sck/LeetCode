class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        ios::sync_with_stdio(0);
        unordered_map<char, bool> a;
        int i = 0, j = 0, ans = 0;
        while (j < s.size()) {
            if (a[s[j]]) {
                while (s[i] != s[j]) a[s[i++]] = 0;
                a[s[j]] = 0; ++i;
            } else {
                a[s[j]] = 1; ++j;
            }
            ans = max(j-i, ans);
        }
        return ans;
    }
};