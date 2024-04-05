class Solution {
public:
    string makeGood(string s) {
        string ans;
        stack<char> st;
        for (int i = 0; i < s.size(); ++i) {
            if (st.empty()) st.push(s[i]);
            else if (abs(s[i] - st.top()) == 32) st.pop();
            else st.push(s[i]);
        }
        while (st.size()) {
            ans += st.top();
            st.pop();
        }
        for (int i = 0; i < ans.size()/2; ++i) {
            swap(ans[i], ans[ans.size()-i-1]);
        }
        return ans;
    }
};