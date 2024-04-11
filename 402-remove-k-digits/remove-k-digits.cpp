class Solution {
public:
    string removeKdigits(string num, int k) {
        int sz = num.size();
        int z = 0;
        for (auto x : num) if (x == '0') ++z;
        if (k >= sz-z) return "0";
        stack<char> st;
        for (auto x : num) {
            while (k && st.size() && x < st.top()) {
                st.pop();
                --k;
            }
            st.push(x);
        }
        while (k && st.size()) {
            st.pop();
            --k;
        }
        string ans;
        stack<char> st2;
        while (st.size()) {
            st2.push(st.top());
            st.pop();
        }
        while (st2.size() && st2.top() == '0') st2.pop();
        while (st2.size()) {
            ans += st2.top();
            st2.pop();
        }
        return ans;
    }
};