class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res(2, -1);
        int i = 0, j = nums.size()-1;
        while (i < j) {
        	int mid = i + j >> 1;
        	if (nums[mid] < target) i = mid + 1;
        	else j = mid;
        }
        if (i == nums.size() || nums[i] != target) return res;
        res[0] = i;
        j = nums.size()-1;
        while (i < j) {
        	int mid = (i + j >> 1) + 1;
        	if (nums[mid] > target) j = mid - 1;
        	else i = mid;
        }
        res[1] = i;
        return res;
    }
};