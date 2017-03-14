class Solution {
public:
    void moveZeroes(vector<int>& nums) {
  		int left = 0, right = 0;
  		while (left < nums.size()) {
  			while (left < nums.size() && nums[left] != 0) ++left;
  			if (left == nums.size()) return;
  			right = max(left+1, right);
  			while (right < nums.size() && nums[right] == 0) ++right;
  			if (right == nums.size()) return;
  			if (right > left) swap(nums[left], nums[right]);
  		}      
    }
};