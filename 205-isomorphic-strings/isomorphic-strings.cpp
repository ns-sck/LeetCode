class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int> v1(128);
        vector<int> v2(128);
        // if (s.size() ^ t.size()) return 0;
        for (int i = 0; i < s.size(); ++i) {
            if (v1[s[i]] ^ v2[t[i]]) return 0;
            v1[s[i]] = v2[t[i]] = i+107;
        }   
        return 1;
    }
};