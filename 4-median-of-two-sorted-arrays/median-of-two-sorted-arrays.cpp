class Solution {
public:

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        ios::sync_with_stdio(0);

        int sz1 = nums1.size(), sz2 = nums2.size();
        if (sz1 > sz2) return findMedianSortedArrays(nums2, nums1);
        if (!sz1) return sz2%2 ? nums2[sz2>>1] : (double) (nums2[sz2>>1] + nums2[(sz2>>1)-1]) / 2;
        if (!sz2) return sz1%1 ? nums1[sz1>>1] : (double) (nums1[sz1>>1] + nums1[(sz1>>1)-1]) / 2;

        int rm = (sz1+sz2+1)>>1, l = 0, h = sz1;
        while (l <= h) {
            int i = (l+h)>>1;
            int j = rm-i;
            int l1 = -1e9, l2 = -1e9, r1 = 1e9, r2 = 1e9;
            if (i) l1 = nums1[i-1];
            if (j) l2 = nums2[j-1];
            if (i < sz1) r1 = nums1[i];
            if (j < sz2) r2 = nums2[j];
            if (l1 <= r2 && l2 <= r1) {
                if ((sz1+sz2)%2) return max(l1, l2);
                else return (double) (max(l1,l2) + min(r1,r2)) / 2;
            } else if (l1 > r2) h = i-1;
            else l = i+1;
        }
        return 0;
    }
}; 