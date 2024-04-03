class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char,char> mp;
        map<char,char> rv;
        // if (s.size() ^ t.size()) return 0;
        for (int i = 0; i < s.size(); ++i) {
            if (mp.count(s[i]) ^ rv.count(t[i])) return 0;
            if (mp.count(s[i]) && (mp[s[i]] != t[i] || rv[t[i]] != s[i])) return 0;
            mp[s[i]] = t[i];
            rv[t[i]] = s[i];
        }
        return 1;
    }
};