class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        int size1 = nums1.size();
        int size2 = nums2.size();
        int total = size1 + size2;
        vector<int> merged(total/2 + 1);

        int j = 0;
        int k = 0;
        for (int i = 0; i < total / 2 + 1; i++) {
            if (j < size1 && k < size2)
                merged[i] = nums1[j] < nums2[k] ? nums1[j++] : nums2[k++];
            else if (j < size1)
                merged[i] = nums1[j++];
            else if (k < size2)
                merged[i] = nums2[k++];
        }
        return total % 2 == 1 ? merged[total/2] : (merged[total/2 - 1] + merged[total/2]) / 2.0;
    }
};