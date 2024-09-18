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
        if (ans[0] == '0') return "0";

        return ans;
    }
};