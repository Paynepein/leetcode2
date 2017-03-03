class Solution {
public:
    void sortColors(vector<int>& nums) {
        int left = 0, right = nums.size()-1;
        for (int i = 0; i < nums.size(); ++i) {
        	while (i < right && nums[i] == 2) swap(nums[i], nums[right--]);
        	while (i > left && nums[i] == 0) swap(nums[i], nums[left++]);
        }
    }
};

