#define ll long long
const int MOD = 1e9+7;
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& w) {
        ios::sync_with_stdio(0);

        int sz1 = s.size(), sz2 = w[0].size(), N = w.size();
        vector<int> ans;

        map<string, int> nd;
        for (string& ss : w) ++nd[ss];
        
        for (int i = 0; i < sz2; ++i) {
            map<string, int> exz;
            bool b = 0;
            for (int k = 0; k < N * sz2; k += sz2) {
                if (k+i+sz2 > sz1) {
                    b = 1;
                    break;
                }
                string ss = s.substr(k+i, sz2);
                ++exz[ss];
            }
            if (b) break;
            int c = 0;
            for (auto& [a, b] : exz) {
                if (nd.count(a) && nd[a] == b) c += b;
            }

            if (c == N) ans.push_back(i);
            for (int j = sz2 + i; j <= sz1 - N * sz2; j += sz2) {
                string rm = s.substr(j-sz2, sz2);
                string in = s.substr(j+(N-1)*sz2, sz2);
                // cout << j << ' ' << rm << exz[rm] << ' ' << in << exz[in] << ' ' << c << '\n';
                if (nd.count(rm)) {
                    if (--exz[rm] == nd[rm]) c += nd[rm];
                    else if (exz[rm] == nd[rm] - 1) c -= nd[rm];
                }
                if (nd.count(in)) {
                    if (++exz[in] == nd[in]) c += nd[in];
                    else if (exz[in] == nd[in] + 1) c -= nd[in];
                }
                if (c == N) ans.push_back(j);
            }
        }
        return ans;
    }
};