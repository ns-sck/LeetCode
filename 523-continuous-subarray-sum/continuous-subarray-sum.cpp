class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        ios::sync_with_stdio(0);
        unordered_map<int, int> mp;
        mp[0] = 0;
        for (int i = 0; i < nums.size(); ++i) {
            nums[i] %= k;
            if (i) nums[i] = (nums[i-1] + nums[i]) % k;
            if (mp.count(nums[i]) && i-mp[nums[i]] >= 1) return 1;
            if (!mp.count(nums[i])) mp[nums[i]] = i+1;
        }
        return 0;
    }
};