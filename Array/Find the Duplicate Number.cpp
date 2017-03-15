class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
        	int j = i;
        	while (nums[j] != j+1) {
        		if (nums[nums[j]-1] == nums[j]) return nums[j];
        		swap(nums[j], nums[nums[j]-1]);
        	}
        }
        return -1;
    }
};