class Solution {
public:
    int findMaxK(vector<int>& nums) {
        unordered_map<int, int> mp;
        int ans = -1;
        for (int i = 0; i < nums.size(); ++i) {
            if (mp[-nums[i]]) ans = max(ans, abs(nums[i]));
            ++mp[nums[i]];
        }
        return ans;
    }
};