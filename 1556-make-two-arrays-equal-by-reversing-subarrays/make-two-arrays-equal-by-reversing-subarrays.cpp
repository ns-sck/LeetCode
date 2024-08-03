class Solution {
public:
    bool canBeEqual(vector<int>& t, vector<int>& a) {
        ios::sync_with_stdio(0);
        sort(t.begin(), t.end());
        sort(a.begin(), a.end());
        return a == t;
    }
};