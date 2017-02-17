class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
    	if (n == 0) return 1;
    	if (n > 10) return countNumbersWithUniqueDigits(10);
        vector<int> dp(10, 0);
        dp[0] = 10;
        int tmp = 9 * 9, last = 9;
        for (int i = 1; i < n; ++i) {
        	dp[i] = tmp + dp[i-1];
        	tmp *= --last;
        }
        return dp[n-1];
    }
};