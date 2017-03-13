class Solution {
public:
    int findPeakElement(vector<int>& nums) {
    	int left = 0, right = nums.size()-1;
    	while (left < right) {
    		int mid = left + (right - left >> 1);
    		if ((mid == 0 || nums[mid] > nums[mid-1]) && nums[mid] > nums[mid+1]) return mid;
    		if (nums[mid] > nums[mid+1]) right = mid-1;
    		else left = mid+1;
    	}
    	return left;
    }
};