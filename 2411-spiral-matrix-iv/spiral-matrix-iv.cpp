class Solution {
public:
    int ar[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        ios::sync_with_stdio(0);
        int mx[4] = {{},{},{},{}};
        int idx = 0;
        int N = m*n, x = 0, y = 0;
        mx[0] = n-1, mx[1] = m-1, mx[2] = 0, mx[3] = 0;
        vector<vector<int>> ans(m, vector<int>(n));
        auto checky = [&](int a) {
            return a <= mx[0] && a >= mx[2];
        };
        auto checkx = [&](int a) {
            return a <= mx[1] && a >= mx[3];
        };
        while (N--) {
            int add = head ? head->val : -1;
            if (head) head = head->next;
            ans[x][y] = add;
            if (checky(y + ar[idx][1]) && checkx(x + ar[idx][0])) {
                x += ar[idx][0];
                y += ar[idx][1];
            } else {
                int xx = (idx+3) % 4;
                mx[xx] -= ar[xx][1-(xx&1)];
                ++idx;
                idx %= 4;
                x += ar[idx][0];
                y += ar[idx][1];
            }
        }
        return ans;
    }
};