class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        ios::sync_with_stdio(0);
        map<int, int> mp;
        priority_queue<pair<int, int>> pq;

        for (int i = 0; i < arr2.size(); ++i) 
            mp[arr2[i]], pq.push({-i, arr2[i]});

        vector<int> ans, rm;

        for (int i = 0; i < arr1.size(); ++i)
            if (mp.count(arr1[i])) ++mp[arr1[i]];
            else rm.push_back(arr1[i]); 

        while (pq.size()) {
            int v = pq.top().second;
            pq.pop();
            while (mp[v]--) ans.push_back(v);
        }
        sort(rm.rbegin(), rm.rend());
        int j = rm.size();
        while (j) ans.push_back(rm[--j]);
        return ans;
    }
};