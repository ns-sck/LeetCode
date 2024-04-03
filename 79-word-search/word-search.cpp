#define ll long long
class Solution {
public:
    int arr[4][2] = {{1,0},{0,1},{0,-1},{-1,0}};
    bool exist(vector<vector<char>>& board, string word) {
        int r = board.size();
        int c = board[0].size();
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                if (board[i][j] != word[0]) continue;
                queue<array<ll,3>> q;
                q.push({i*c+j,0,0});
                while (q.size()) {
                    auto p = q.front();
                    q.pop();
                    int n = p[0];
                    int st = p[1];
                    ll msk = p[2];
                    int rr = n / c;
                    int cc = n % c;
                    if ((1LL << n) & msk) continue;
                    msk |= (1LL << n);
                    if (st >= word.size() || word[st] != board[rr][cc]) continue;
                    if (word[st] == board[rr][cc] && st == word.size() - 1) return 1;
                    for (auto x : arr) {
                        int nr = x[0] + rr;
                        int nc = x[1] + cc;
                        if (~nr && nr < r && ~nc && nc < c) q.push({nr*c+nc,st+1,msk});
                    }
                }
            }
        }
        return 0;
    }
};