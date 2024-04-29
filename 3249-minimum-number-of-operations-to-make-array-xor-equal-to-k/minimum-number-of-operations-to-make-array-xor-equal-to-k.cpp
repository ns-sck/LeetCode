class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int x = 0, ans = 0;
        int b[21]; memset(b, 0, sizeof(b));
        for (auto& y : nums) {
            int c = 0;
            while (y) {
                if (y&1) ++b[c];
                y >>= 1; ++c;
            }
        }
        for (int i = 0; i < 21; ++i)
            cout << b[i] << '\n';
        while (k) {
            if ((k&1) ^ (b[x++]&1)) ++ans;
            k >>= 1;
        }
        while (x < 21) if (b[x++]&1) ++ans;
        return ans;
    }
};