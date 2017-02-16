class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(amount+1, vector<int>(coins.size()+1, INT_MAX));
        for (int i = 1; i <= amount; ++i) {
        	for (int j = 1; j <= coins.size(); ++j) {
        		if (coins[j] > i+1) {
        			dp[i][j] = dp[i][j-1];
        		} else {
        			dp[i][j] = min(dp[i][j-1], dp[i + 1 - coins[j]] + 1);
        		}
        	}
        }
    }
};