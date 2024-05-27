class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int sz = nums.size();
        if (nums[0] >= sz) return sz;
        int l = 1, h = sz-1;
        while (l <= h) {
            int m = (l+h) / 2;
            int idx = sz-m;
            if (nums[idx] >= m && nums[idx-1] < m) return m;
            if (nums[idx] >= m) l = m+1;
            else h = m-1;
        }
        return -1;
    }
};