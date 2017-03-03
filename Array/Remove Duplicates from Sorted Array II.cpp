class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
    	if (nums.size() < 3) return nums.size();
        sort(nums.begin(), nums.end());
        int left = 2;
        for (int i = 2; i < nums.size(); ++i) {
        	if (nums[i] != nums[left-2]) {
        		nums[left++] = nums[i];
        	}
        }
        return left;
    }
};