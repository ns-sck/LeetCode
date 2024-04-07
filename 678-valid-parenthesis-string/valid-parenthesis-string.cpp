class Solution {
public:
    bool checkValidString(string s) {
        stack<int> s1;
        stack<int> s2;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') s1.push(i);
            if (s[i] == ')') {
                if (s1.size()) s1.pop();
                else if (s2.size()) s2.pop();
                else return 0;
            }
            if (s[i] == '*') s2.push(i);
        }
        while (s1.size()) {
            if (s2.size()) {
                if (s2.top() > s1.top()) {
                    s1.pop();
                    s2.pop();
                } else return 0;
            } else return 0;
        }
        return 1;
    }
};