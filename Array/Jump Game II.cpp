class Solution {
public:
    int jump(vector<int>& nums) {
  		int count = 0, start = 0, end = 0, maxReach = 0;
  		while (start < nums.size()-1) {
  			++count;
  			for (int i = start; i <= end; ++i) {
  				maxReach = max(maxReach, nums[i] + i);
  			}
  			if (maxReach >= nums.size()-1) return count;
  			start = end+1;
  			end = maxReach;
  		}
  		return count;
    }
};