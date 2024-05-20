class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        return dfs(nums, 0, 0);
    }
    int dfs(vector<int>& nums, int t, int i) {
        if (i == nums.size()) return t;
        return dfs(nums, t^nums[i], i+1) + dfs(nums, t, i+1);
    }
};