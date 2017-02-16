class Solution {
public:
    int maxCoins(vector<int>& nums) {
    	nums.insert(nums.begin(), 1);
    	nums.insert(nums.end(), 1);
        vector<vector<int>> dp(nums.size(), vector<int>(nums.size(), 0));
        for (int len = 1; len <= nums.size() - 2; ++len) {
        	for (int i = 1; i < nums.size() - len; ++i) {
        		int j = i + len - 1;
        		for (int x = i; x <= j; ++x) {
        			dp[i][j] = max(dp[i][j], dp[i][x-1] + nums[i-1] * nums[x] * nums[j+1] + dp[x+1][j]);
        		}
        	}
        }
        return dp[1][nums.size()-2];
    }
};