class Solution {
public:
    bool canJump(vector<int>& nums) {
        int start = 0, end = 0, maxReach = 0;
        while (maxReach < nums.size()-1) {
        	for (int i = start; i <= end; ++i) {
        		maxReach = max(maxReach, i + nums[i]);
        	}
        	if (maxReach <= end) return false;
        	start = end+1;
        	end = maxReach;
        }
        return true;
    }
};