class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.size() == 0) return 0;
    	int m = grid.size(), n = grid[0].size();
        vector<int> dp(n, 0);
        for (int i = m-1; i >= 0; --i) {
            for (int j = n-1; j >= 0; --j) {
                if (j == n-1) {
                    dp[j] += grid[i][j];
                } else if (i == m-1) {
                    dp[j] = grid[i][j] + dp[j+1];
                } else {
                    dp[j] = min(dp[j], dp[j+1]) + grid[i][j];
                }
            }
        }
        return dp[0];
    }
};