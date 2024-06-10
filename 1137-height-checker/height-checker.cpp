class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> n = heights;
        sort(n.begin(), n.end());
        int ans = 0;
        for (int i = 0; i < n.size(); ++i) {
            ans += n[i] != heights[i];
        }
        return ans;
    }
};