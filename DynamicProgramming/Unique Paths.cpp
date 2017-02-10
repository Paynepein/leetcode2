class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> dp(n, 1);
        for (int i = m-2; i >= 0; --i) {
        	for (int j = n-1; j >= 0; --j) {
        		dp[j] += j + 1 == n ? 0 : dp[j+1];
        	}
        }
        return dp[0];
    }
};