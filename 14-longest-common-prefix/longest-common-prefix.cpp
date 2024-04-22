class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int j = -1, sz = strs.size();
        if (strs.empty()) return "";
        string ans;
        while (1) {
            if (++j >= (int) strs[0].size()) break;
            char c = strs[0][j];
            for (int i = 1; i < sz; ++i) {
                if (strs[i].size() <= j || strs[i][j] != c) return ans;
            }
            ans += strs[0][j];
        }
        return ans;
    }
};