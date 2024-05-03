class Solution {
public:
    int compareVersion(string s1, string s2) {
        int i = 0, j = 0, len1 = s1.size(), len2 = s2.size();
        while (i < len1 && j < len2) {
            string l1, l2;
            while (i < len1 && s1[i] != '.') {
                l1 += s1[i++];
            }
            while (j < len2 && s2[j] != '.') {
                l2 += s2[j++];
            }
            if (stoi(l1) > stoi(l2)) return 1;
            if (stoi(l1) < stoi(l2)) return -1;
            ++i; ++j;
        }
        while (i < len1) {
            if (s1[i] != '0' && s1[i] != '.')
                return 1;
            ++i;
        }
        while (j < len2) {
            if (s2[j] != '0' && s2[j] != '.')
                return -1;
            ++j;
        }

        return 0;
    }
};