class Solution {
public:
    string minRemoveToMakeValid(string s) {
        vector<bool> b(1e5);
        string ans = "";
        stack<int> st;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') st.push(i);
            if (s[i] == ')') {
                if (st.size()) {
                    b[i] = b[st.top()] = 1;
                    st.pop();
                }
            }
        }
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == ')' || s[i] == '(') {
                if (b[i]) ans += s[i];
            }
            else ans += s[i];
        }
        return ans;
    }
};