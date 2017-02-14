class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
    	return max(robHelper(nums, 0, nums.size()-2), robHelper(nums, 1, nums.size()-1));
    }

    int robHelper(vector<int>& nums, int start, int end) {
    	if (start > end) return 0;
    	int prepre = 0, pre = nums[start], here = nums[start];
    	for (int i = start + 1; i <= end; ++i) {
    		here = max(prepre + nums[i], pre);
    		prepre = pre;
    		pre = here;
    	}
    	return here;
    }
};