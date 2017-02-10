class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<int> dp(n, 0);
        for (int i = 0; i < n; ++i) {
        	if (obstacleGrid[0][i] != 1) dp[i] = 1;
        	else break;
        }
        for (int i = 1; i < m; ++i) {
        	for (int j = 0; j < n; ++j) {
        		if (obstacleGrid[i][j] == 1) {
        			dp[j] = 0;
        		} else {
        			dp[j] += j == 0 ? 0 : dp[j-1];
        		}
        	}
        }
        return dp[n-1];
    }
};