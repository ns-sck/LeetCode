class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        ios::sync_with_stdio;
        set<int> s;
        vector<vector<int>> ans;
        for (auto x : nums) s.insert(x);
        for (int i = 0; i < (1 << s.size()); ++i) {
            vector<int> v;
            for (int j = 0; j < s.size(); ++j) {
                if (i & (1 << j)) v.push_back(nums[j]);
            }
            ans.push_back(v);
        }
        return ans;
    }
};