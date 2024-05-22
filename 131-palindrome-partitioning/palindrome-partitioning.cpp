#define ll long long
const int MOD = 1e9+7;

class Solution {
public:
    std::vector<std::vector<std::string>> ans;
    ll sz;
    std::vector<ll> pws, hsh, hshr;
    std::string s;

    ll fp(ll base, ll exp) {
        ll result = 1;
        while (exp > 0) {
            if (exp % 2 == 1)
                result = (result * base) % MOD;
            base = (base * base) % MOD;
            exp /= 2;
        }
        return result;
    }

    std::vector<std::vector<std::string>> partition(std::string s) {
        this->s = s;
        this->sz = s.size();
        pws.resize(sz + 1, 1);
        hsh.resize(sz + 1, 0);
        hshr.resize(sz + 1, 0);

        for (int i = 1; i <= sz; ++i) {
            pws[i] = (pws[i - 1] * 37) % MOD;
        }
        
        for (int i = 1; i <= sz; ++i) {
            hsh[i] = (hsh[i - 1] + pws[i] * (s[i - 1] - 'a' + 1)) % MOD;
        }

        for (int i = sz - 1; i >= 0; --i) {
            hshr[i] = (hshr[i + 1] + pws[sz - i] * (s[i] - 'a' + 1)) % MOD;
        }

        std::vector<int> v;
        rec(v, 0, 0);
        return ans;
    }

    void rec(vector<int> v, int l, int r) {
        // cout << l << ' ' << r << '\n';
        if (r >= sz && l < sz) return;
        if (l >= sz) {
            vector<string> vs;
            v.push_back(sz);
            for (int i = 0; i < v.size()-1; ++i) {
                vs.push_back(s.substr(v[i], (v[i+1]-v[i])));
            }
            ans.push_back(vs);
            return;
        }
        rec(v, l, r+1);
        ll h = ((hsh[r+1] - hsh[l]) * fp(pws[l], MOD-2)) % MOD;
        if (h < 0) h += MOD;
        ll hr = ((hshr[l] - hshr[r+1]) * fp(pws[sz-r-1], MOD-2)) % MOD;
        if (hr < 0) hr += MOD;
        // cout << l << ' ' << r << "--> ";
        // cout << h << ' ' << hr << '\n';
        if (h == hr) {
            v.push_back(l);
            rec(v, r+1, r+1);
        }
    }
};