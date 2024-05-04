class Solution {
public:
    int numRescueBoats(vector<int>& p, int limit) {
        std::ios_base::sync_with_stdio(0);
	    std::cin.tie(0);
        sort(p.begin(), p.end());
        int i = 0, j = p.size()-1, ans = 0;
        while (i <= j) {
            if (p[i]+p[j] <= limit) {
                ++i, --j;
            } else {
                --j;
            }
            ++ans;
        }
        return ans;
    }
};