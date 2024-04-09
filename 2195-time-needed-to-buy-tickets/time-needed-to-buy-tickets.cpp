class Solution {
public:
    int timeRequiredToBuy(vector<int>& t, int k) {
        int l = 0 , r = 0;
        for (int i = 0; i <= k; ++i) {
            if (t[i] > t[k]) l += t[k];
            else l += t[i];
        }
        for (int i = k+1; i < t.size(); ++i) {
            if (t[i] >= t[k]) r += t[k]-1;
            else r += t[i];
            cout << r << ' ';
        }
        return l + r;
    }
};