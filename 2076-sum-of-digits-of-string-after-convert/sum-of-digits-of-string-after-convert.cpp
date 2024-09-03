class Solution {
public:
    int getLucky(string s, int k) {
        ios::sync_with_stdio(0);
        int x = 0;
        string ss;
        for (int i = 0; i < s.size(); ++i) {
            int a = s[i] - 'a' + 1;
            ss += to_string(a);
        }
        while (k--) {
            x = 0;
            for (int i = 0; i < ss.size(); ++i) {
                x += ss[i] - '0';
            }
            ss = to_string(x);
        }
        return x;
    }
};