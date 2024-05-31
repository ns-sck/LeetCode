class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        ios::sync_with_stdio(0);
        vector<pair<int, int>> v;
        for (int i = 0; i < nums.size(); ++i) v.push_back({nums[i], i});
        sort(v.begin(), v.end());
        int i = 0, j = v.size()-1;
        while (i < j) {
            if (v[i].first + v[j].first == target) return {v[i].second, v[j].second};
            if (v[i].first + v[j].first > target) --j;
            else ++i;
        }
        return {};
    }
};