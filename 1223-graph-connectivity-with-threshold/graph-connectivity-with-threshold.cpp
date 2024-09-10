class Solution {
public:

    vector<int> par;
    vector<int> sz;

    int find(int u) {
        return u == par[u] ? u : par[u] = find(par[u]);
    }
    
    void uni(int u, int v) {
        u = find(u), v = find(v);
        if (u == v) return;
        if (sz[u] > sz[v]) swap(u, v);
        par[u] = v;
        sz[v] += sz[u];
    }

    vector<bool> areConnected(int N, int th, vector<vector<int>>& queries) {
        ios::sync_with_stdio(0);
        
        par.resize(N+1);
        sz.resize(N+1);
        vector<vector<int>> div(N+1);

        for (int i = 1; i <= N; ++i) {
            sz[i] = 1;
            par[i] = i;
            for (int j = i; j <= N; j += i) {
                div[j].push_back(i);
            }
        }

        vector<bool> ans;

        for (int i = th+1; i <= N; ++i) {
            for (int j = 0; j < div[i].size(); ++j) {
                int x = i / div[i][j];
                if (x <= th) break;
                uni(i, x);
            }
        }

        for (int i = 0; i < queries.size(); ++i) {
            ans.push_back(find(queries[i][0]) == find(queries[i][1]));
        }

        return ans;
    }       
};