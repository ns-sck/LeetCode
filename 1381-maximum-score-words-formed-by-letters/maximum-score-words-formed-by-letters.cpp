class Solution {
public:
    vector<string> w;
    vector<int> sc;
    int ch[26], ans = 0;
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        ios::sync_with_stdio;
        sc = score;
        memset(ch, 0, sizeof(ch));  
        for (auto c : letters) ++ch[c-'a'];
        for (auto s : words) {
            vector<int> v(26);
            bool b = 1;
            for (auto c : s) {
                ++v[c-'a'];
                if (v[c-'a'] > ch[c-'a']) b = 0;
            }
            if (b) w.push_back(s);
        }
        dfs(0, 0);
        return ans;
    }
    void dfs(int i, int t) {
        if (i == w.size()) {
            ans = max(ans, t);
            return;
        }
        bool b = 1;
        int add = 0;
        for (auto c : w[i]) {
            if (--ch[c-'a'] < 0) b = 0;
            else add += sc[c-'a']; 
        }
        if (b) dfs(i+1, t+add);
        for (auto c : w[i]) ++ch[c-'a'];
        dfs(i+1, t);
    }
};