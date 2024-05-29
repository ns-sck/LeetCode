class Solution {
public:
    int numSteps(string s) {
        ios::sync_with_stdio;
        int ans = 0;
        while (s.size() > 1) {
            int i = s.size()-1;
            if (s[i]-'0') {
                s[i--] = '0';
                while (~i && s[i]-'0') {
                    s[i--] = '0';
                }
                if (~i) s[i] = '1';
            } else s.pop_back();
            ++ans;
        }
        if (s.size() && s[0] == '0') ++ans; 
        return ans;
    }
};