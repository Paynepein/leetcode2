class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
    	if (prices.size() <= 1) return 0;
    	if (prices.size() / 2 <= k) return maxProfitAny(prices);
        vector<vector<int>> dp(k+1, vector<int>(prices.size(), 0));
        for (int i = 1; i <= k; ++i) {
        	int remain = - prices[0];
        	for (int j = 1; j < prices.size(); ++j) {
        		dp[i][j] = max(dp[i][j-1], prices[j] + remain);
        		remain = max(remain, dp[i-1][j-1] - prices[j]);
        	}
        }
        return dp[k][prices.size()-1];
    }

    int maxProfitAny(vector<int>& prices) {
    	int profit = 0;
    	for (int i = 1 ; i < prices.size(); ++i) {
    		if (prices[i] - prices[i-1] > 0) profit += prices[i] - prices[i-1];
    	}
    	return profit;
    }
};