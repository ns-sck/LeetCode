bool srt(pair<int, int> p, pair<int, int> p2) {
    return (double)(p.first / (double)p.second) < (double)(p2.first / (double)p2.second); 
}
class Solution {
public:
    
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        vector<pair<int, int>> ans;
        for (int i = 0; i < arr.size(); ++i) {
            for (int j = i+1; j < arr.size(); ++j) {
                ans.push_back({arr[i], arr[j]});
            }
        }
        sort(ans.begin(), ans.end(), srt);
        return {ans[k-1].first, ans[k-1].second};
    }
};