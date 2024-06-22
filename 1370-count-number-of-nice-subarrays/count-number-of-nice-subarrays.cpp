class Solution {
public:
    int numberOfSubarrays(vector<int>& v, int K) {
        ios::sync_with_stdio(0);
        int N = v.size();

        vector<int> idx = {-1};
        for (int i = 0; i < N; ++i) 
            if (v[i]%2) idx.push_back(i);
        idx.push_back(N);
        
        if (idx.size() < K+2) return 0;
        int i = 0, j = K, ans = 0;

        while (j < idx.size()-1) {
            int d1 = idx[j+1]-idx[j], d2 = idx[i+1]-idx[i];
            ans += d1*d2;
            ++i, ++j;
        }
        return ans;
    }
};