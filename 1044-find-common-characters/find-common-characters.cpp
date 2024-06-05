class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int> ans(26, 1e9);
        for (auto& s : words) {
            vector<int> a(26);
            for (auto c : s) ++a[c-'a'];
            for (int i = 0; i < 26; ++i) ans[i] = min(ans[i], a[i]);
        }
        vector<string> res;
        for (int i = 0; i < 26; ++i) 
            for (int j = 0; j < ans[i]; ++j) res.push_back(string(1, 'a'+i));
        return res;
    }
};