class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& p, vector<int>& c) {
        ios::sync_with_stdio(0);
        int N = p.size();
        vector<pair<int, int>> mrg;

        for (int i = 0; i < N; ++i) mrg.push_back({c[i], p[i]});
        sort(mrg.begin(), mrg.end());

        priority_queue<int> pq;
        int i = 0;
        while (k--) {
            while (i < N && w >= mrg[i].first)
                pq.push(mrg[i++].second);
            if (!pq.size()) break;
            w += pq.top();
            pq.pop();
        }    
        return w;
    }
};