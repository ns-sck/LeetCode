class Solution {
public:
    pair<int, int> go[4] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        ios::sync_with_stdio(0);
        int idx = 0, ans = 0, x = 0, y = 0;
        map<pair<int, int>, int> mp;

        for (auto& v : obstacles) {
            mp[{v[0], v[1]}] = 1;
        }

        for (int& c : commands) {
            if (c == -2) idx = (idx + 4 - 1) % 4; 
            else if (c == -1) idx = (idx + 1) % 4;
            else {
               while (c--) {
                    int nx = go[idx].first + x;
                    int ny = go[idx].second + y;
                    if (mp[{nx, ny}]) break;
                    x = nx;
                    y = ny;
                }
                ans = max(ans, x*x + y*y); 
            }
        }
        return ans;
    }
};