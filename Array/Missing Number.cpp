class Solution {
public:
    int missingNumber(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
        	int j = i;
        	while (nums[j] != j && nums[j] < nums.size()) {
        		swap(nums[nums[j]], nums[j]);
        	}
        }
        for (int i = 0; i < nums.size(); ++i) {
        	if (nums[i] != i) return i;
        }
        return nums.size();
    }
};