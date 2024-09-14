class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        ios::sync_with_stdio(0);
        int mx = 0, c = 0, ans = 0;
        for (int i = 0; i < nums.size(); ++i) mx = max(mx, nums[i]);
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] ^ mx) {
                c = 0;
                continue;
            }
            else {
                ++c;
                ans = max(ans, c);
            }
        }
        return ans;
    }
};