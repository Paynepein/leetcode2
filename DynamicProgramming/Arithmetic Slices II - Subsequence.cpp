class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        vector<unordered_map<int, int>> dp(A.size());
        int res = 0;
        for (int i = 0; i < A.size(); ++i) {
        	for (int j = 0; j < i; ++j) {
        		if (long(A[i]) - long(A[j]) < INT_MIN || long(A[i]) - long(A[j]) > INT_MAX) continue;
        		int diff = A[i] - A[j];
        		dp[i][diff] += 1;
        		if (dp[j].find(diff) != dp[j].end()) {
        			dp[i][diff] += dp[j][diff];
        			res += dp[j][diff];
        		}
        	}
        }
        return res;
    }
};