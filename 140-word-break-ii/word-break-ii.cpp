class Solution {
public:
    vector<vector<int>> st;
    vector<string> ans;
    vector<string> dict;
    string s;
    vector<string> wordBreak(string s, vector<string>& dict) {
        int sz1 = s.size(), sz2 = dict.size();
        st.resize(sz1);

        this->dict = dict;
        this->s = s;
        map<string, int> mp;

        for (int i = 0; i < sz2; ++i) mp[dict[i]] = i+1;

        for (int i = 0; i < sz1; ++i) {
            for (int j = i; j < sz1; ++j) {
                string ss = s.substr(i, j-i+1);
                if (mp[ss]) st[i].push_back(mp[ss]-1);
            }
        }

        rec(0, vector<int>());
        return ans;
    }

    void rec(int i, vector<int> v) {
        if (i == s.size()) {
            string snt;
            for (auto j : v) {
                snt += dict[j];
                snt += ' ';
            }
            snt.pop_back();
            ans.push_back(snt);
            return;
        }

        if (i > s.size()) return;

        for (auto x : st[i]) {
            v.push_back(x);
            rec(i+dict[x].size(), v);
            v.pop_back();
        }
    }
};