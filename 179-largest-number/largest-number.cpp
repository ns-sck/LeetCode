class Solution {
public:
    string largestNumber(vector<int>& nums) {
        ios::sync_with_stdio(0);
        vector<string> v;
        for (auto& x : nums) {
            v.push_back(to_string(x));
        }

        sort(v.begin(), v.end(), [](string& a, string& b) {
            return a + b > b + a;
        });

        string ans;
        for (string& s : v) {
            ans += s;
        }
        bool b = 0;
        for (int i = 0; i < ans.size(); ++i) b |= ans[i] != '0';
        if (!b) return "0";

        return ans;
    }
};