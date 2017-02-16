class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> res(k, 0);
        int m = min(k, int(nums1.size()));
        for (int i = max(0, int(k - nums2.size())); i <= m; ++i) {
            vector<int> tmpNum = merge(maxNumberHelper(nums1, i), i, maxNumberHelper(nums2, k - i), k - i);
            if (greater(res, 0, tmpNum, 0)) res = move(tmpNum);
        }
        return res;
    }

    bool greater(vector<int>& nums1, int i, vector<int>& nums2, int j) {
        for (; i < nums1.size() && j < nums2.size() && nums1[i] == nums2[j]; ++i, ++j) {
        }
        return i == nums1.size() || (j != nums2.size() && nums1[i] < nums2[j]);
    }

    vector<int> merge(vector<int> nums1, int n1, vector<int> nums2, int n2) {
        vector<int> res(n1+n2, 0);
        int index = 0, index1 = 0, index2 = 0;
        while (index1 < n1 && index2 < n2) {
            res[index++] = greater(nums1, index1, nums2, index2) ? nums2[index2++] : nums1[index1++];
        }
        while (index1 < n1) res[index++] = nums1[index1++];
        while (index2 < n2) res[index++] = nums2[index2++];
        return res;
    }

    vector<int> maxNumberHelper(vector<int>& nums, int k) {
        vector<int> res(k, 0);
        if (k == 0) return res;
        res[0] = nums[0];
        int index = 1;
        for (int i = 1; i < nums.size(); ++i) {
            while (index > 0 && k - index < nums.size() - i && res[index-1] < nums[i]) {
                --index;
            }
            if (index < k) {
                res[index++] = nums[i];
            }
        }
        return res;
    }
};