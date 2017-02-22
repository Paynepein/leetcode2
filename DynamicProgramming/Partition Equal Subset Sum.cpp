class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int nm : nums) sum += nm;
        if (sum & 1) return false;
    	sum >>= 1;
    	vector<bool> dp(sum + 1, false);
    	dp[0] = true;
    	for (int nm : nums) {
    		for (int i = sum; i > 0; --i) {
    			if (i >= nm) {
    				dp[i] = dp[i] || dp[i-nm];
    			}
    		}
    	}
    	return dp[sum];
    }
};