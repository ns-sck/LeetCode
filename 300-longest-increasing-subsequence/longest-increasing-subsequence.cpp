class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int sz = nums.size();
        int ans = 1;
        vector<int> dp(sz+1, 1);
        for (int i = 0; i < sz; ++i) {
            for (int j = i+1; j < sz; ++j) {
                dp[j] = max(dp[j], (nums[j] > nums[i] ? dp[i]+1 : -1));
                ans = max(ans, dp[j]);
            }   
        }
        return ans;
    }
};