class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = -1e9, t = 0;
        for (int i = 0; i < nums.size(); ++i) {
            t = max(t+nums[i], nums[i]);
            ans = max(ans, t);
        }
        return ans;
    }
};