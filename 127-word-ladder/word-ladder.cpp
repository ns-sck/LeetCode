#define w wordList
class Solution {
public:
    bool dff(string& s1, string& s2) {
        bool b = 0;
        if (s1 == s2) return 0;
        for (int i = 0; i < s1.size(); ++i) {
            if (s1[i] != s2[i]) {
                if (b) return false;
                b = 1;
            } 
        }
        return 1;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int _max = w.size();
        vector<int> dp(_max+1, 1e9);
        vector<vector<int>> adj(_max+1, vector<int>());
        int sz = wordList.size();
        for (int i = 0; i < sz; ++i) {
            if (dff(beginWord, w[i])) adj[_max].push_back(i);
            for (int j = 0; j < sz; ++j) {
                if (dff(w[i], w[j])) {
                    adj[i].push_back(j);
                }
            }
        }
        int ans = 1e9;
        queue<array<int, 2>> q;
        q.push({_max, 1});
        while (q.size()) {
            int idx = q.front()[0];
            int st = q.front()[1];
            q.pop();
            if (dp[idx] < st) continue;
            if (idx != _max && w[idx] == endWord) {
                ans = st;
                break;
            };
            dp[idx] = st;
            for (auto x : adj[idx]) {
                if (dp[x] > st+1) q.push({x, st+1});
            }
        }
        if (ans == 1e9) return 0;
        return ans;
    }
};