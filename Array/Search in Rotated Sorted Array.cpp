class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1;
        while (left <= right) {
            int mid = right + left >> 1;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] > nums[right]) {
                if (nums[mid] < target || nums[left] > target) {
                    left = mid+1;
                } else {
                    right = mid-1;
                }
            } else {
                if (nums[right] >= target && nums[mid] < target) {
                    left = mid+1;
                } else {
                    right = mid-1;
                }
            }
        }
        return -1;
    }
};