class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
    	if (A.size() == 0) return 0;
  		vector<int> dp(A.size(), 0);
  		for (int i = 2; i < A.size(); ++i) {
  			int diff = A[i] - A[i-1], j = i-1;
  			while (j > 0 && A[j] - A[j-1] == diff) --j;
  			dp[i] = dp[i-1] + i-1-j;
  		}   
  		return dp.back();
    }
};