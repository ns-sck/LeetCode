#define ll long long
const int MOD = 1e9+7;
class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        ios::sync_with_stdio(0);
        unordered_map<int, bool> mp;
        vector<ll> p(101);
        ll x = 1;
        for (int i = 0; i < 101; ++i) {
            p[i] = x;
            x = (x*37) % MOD;
        }
        for (auto& s : dictionary) {
            int h = 0;
            for (int i = 0; i < s.size(); ++i) {
                int c = s[i]-'a'+1;
                h = (h+c*p[i]) % MOD;
            }
            mp[h] = 1;
        }
        int i = 0;
        string ans;
        sentence += ' ';
        while (i < sentence.size()) {
            string s;
            ll j = i-1, h = 0;
            while (sentence[++j] != ' ') {
                if (j-i > 99) {
                    while (sentence[j] != ' ') s+= sentence[j++];
                    break;
                }
                s += sentence[j];
                int c = sentence[j]-'a'+1;
                h = (h+c*p[j-i]) % MOD;
                if (mp[h]) {
                    while (sentence[++j] != ' ');
                    break;
                }
            }
            ans += s; ans += ' ';
            i = j+1;
        }
        ans.pop_back();
        return ans;
    }
};