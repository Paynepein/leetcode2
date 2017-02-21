class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        for (int right = 2; right <= n; ++right) {
        	for (int left = right-1; left > 0; --left) {
        		int money = INT_MAX;
        		for (int i = left; i < right; ++i) {
        			money = min(money, i + max(dp[left][i-1], dp[i+1][right]));
        		}
        		dp[left][right] = money;
        	}
        }
        return dp[1][n];
    }
};