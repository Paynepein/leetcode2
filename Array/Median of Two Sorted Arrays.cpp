class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        if ((m + n) & 1) return findKthSortedArrays(nums1, 0, m, nums2, 0, n, m+n+1>>1);
        return (findKthSortedArrays(nums1, 0, m, nums2, 0, n, m+n>>1) + findKthSortedArrays(nums1, 0, m, nums2, 0, n, (m+n>>1)+1)) / 2;
    }

    double findKthSortedArrays(vector<int>& nums1, int s1, int m, vector<int>& nums2, int s2, int n, int k) {
    	if (m > n) return findKthSortedArrays(nums2, s2, n, nums1, s1, m, k);
    	if (m == 0) return nums2[k-1];
    	if (k == 1) return min(nums1[s1], nums2[s2]);
    	int p = min(k / 2, m), q = k - p;
    	if (nums1[s1 + p-1] < nums2[s2 + q-1]) return findKthSortedArrays(nums1, s1 + p, m - p, nums2, s2, n, k - p);
    	return findKthSortedArrays(nums1, s1, m, nums2, s2 + q, n-q, k-q);
    }
};