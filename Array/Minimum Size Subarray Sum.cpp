class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
    	long sum = 0;
    	int left = 0, res = INT_MAX;
    	for (int right = 0; right < nums.size(); ++right) {
    		sum += nums[right];
    		while (sum >= s) {
    			sum -= nums[left];
    			res = min(res, right - left++ + 1);
    		}
    	}
    	return res == INT_MAX ? 0 : res;
    }
};