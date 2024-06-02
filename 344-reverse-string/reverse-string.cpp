class Solution {
public:
    void reverseString(vector<char>& s) {
        int i = -1, j = s.size();
        while (++i < --j) swap(s[i], s[j]);
    }
};