class Solution {
public:  
    // not my solution
    vector<vector<int>> g;
    vector<int> n;
    int z = 0;
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        z = k;
        n = nums;
        g = vector<vector<int>>(nums.size());
        for (auto& e : edges){
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        return dfs(0, -1).second;
    }
    pair<long long, long long> dfs(int node, int parent){
        long long smallestDifference = LLONG_MAX, sum = 0;
        bool orientationNormal = true;
        for (auto& e : g[node]) {
            if (e != parent) {
                auto [f, s] = dfs(e, node);
                sum += max(f, s);
                if (abs(f - s) < smallestDifference) smallestDifference = abs(f - s);
                if (f > s) orientationNormal = !orientationNormal;
            }
        }
        pair<long long, long long> ans = {0, 0};
        long long a = n[node], b = n[node] ^ z;
        if (orientationNormal){
            ans.second = max(sum + a, sum + b - smallestDifference);
            ans.first += max(sum + b, sum + a - smallestDifference);
        }
        else {
            ans.first = max(sum + a, sum + b - smallestDifference);
            ans.second += max(sum + b, sum + a - smallestDifference);
        }
        return ans;
    }
};