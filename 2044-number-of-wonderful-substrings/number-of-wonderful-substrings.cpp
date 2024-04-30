#define ll long long
class Solution {
public:
    long long wonderfulSubstrings(string word) {
        ll m = 0, ans = 0;
        ll mp[1 << 10];
        memset(mp, 0, sizeof(mp));
        mp[0] = 1;
        for (int i = 0; i < word.size(); ++i) {
            int a = word[i] - 'a';
            m ^= (1 << a);
            ++mp[m];
            ans += mp[m]-1;
            for (int j = 0; j < 10; ++j) {
                ans += mp[m^(1<<j)];
            }
        }

        return ans;
    }
};