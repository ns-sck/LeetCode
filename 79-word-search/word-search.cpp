#define ll long long
class Solution {
public:
    int arr[4][2] = {{1,0},{0,1},{0,-1},{-1,0}};
    bool exist(vector<vector<char>>& board, string word) {
        int r = board.size();
        int c = board[0].size();
        for (int i = r-1; ~i; --i) {
            for (int j = c-1; ~j; --j) {
                if (board[i][j] != word[0]) continue;
                stack<array<ll,3>> s;
                s.push({i*c+j,0,0});
                while (s.size()) {
                    auto [n, st, msk] = s.top();
                    s.pop();
                    int rr = n / c;
                    int cc = n % c;
                    if ((1LL << n) & msk) continue;
                    msk |= (1LL << n);
                    if (st >= word.size() || word[st] != board[rr][cc]) continue;
                    if (st == word.size() - 1) return 1;
                    for (auto& x : arr) {
                        int nr = x[0] + rr;
                        int nc = x[1] + cc;
                        if (~nr && nr < r && ~nc && nc < c) s.push({nr*c+nc,st+1,msk});
                    }
                }
            }
        }
        return 0;
    }
};