class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        ios::sync_with_stdio(0);
        int ans = 0;
        vector<bool> a(26);
        for (char& c : allowed) a[c-'a'] = 1;
        for (string& w : words) {
            bool b = 1;
            for (char& c : w) b &= a[c-'a'];
            ans += b;
        }
        return ans;
    }
};