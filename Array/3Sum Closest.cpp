class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int res = INT_MAX;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 2; ++i) {
        	int left = i+1, right = nums.size()-1;
        	while (left < right) {
        		int diff = nums[i] + nums[left] + nums[right] - target;
        		if (diff == 0) {
        			return target;
        		} else if (diff < 0) {
        			++left;
        		} else {
        			--right;
        		}
        		if (res == INT_MAX || abs(diff) < abs(res - target)) {
        			res = diff + target;
        		}
        	}
        }
        return res;
    }
};