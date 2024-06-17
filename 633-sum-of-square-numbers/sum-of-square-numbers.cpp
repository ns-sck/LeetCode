class Solution {
public:
    bool judgeSquareSum(int c) {
        ios::sync_with_stdio(0);
        int x = sqrt(c>>1);

        for (int i = 0; i <= x; ++i) {
            int y = sqrt(c-i*i);
            if (y*y + i*i == c) return 1;
        }
        return 0;
    }
};