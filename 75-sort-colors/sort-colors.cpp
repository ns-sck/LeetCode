class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> v(3);
        for (auto& x : nums) ++v[x];
        int i = 0, j = 0;
        while (j != nums.size()) {
            if (v[i]) nums[j++] = i, --v[i];
            else ++i;
        }        
    }
};