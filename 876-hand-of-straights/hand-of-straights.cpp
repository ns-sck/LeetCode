class Solution {
public:
    bool isNStraightHand(vector<int>& v, int g) {
        ios::sync_with_stdio(0);
        if (v.size()%g) return 0;
        
        map<int, int> mp;
        for (auto& x : v) ++mp[x];

        while (mp.size()) {
            auto it = mp.begin();
            for (int i = 0; i < g; ++i) {
                if (it == mp.end()) return 0;
                int x = it->first;
                --it->second;
                if (it->second <= 0) {
                    auto it2 = it;
                    ++it;
                    mp.erase(it2);
                } else ++it;
                if (i^g-1 && it != mp.end() && it->first ^ (x+1)) return 0;
            }
        }
        return 1;
    }
};  