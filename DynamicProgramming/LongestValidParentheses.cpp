class Solution {
public:
    int longestValidParentheses(string s) {
    	if (s.size() == 0) return 0;
    	vector<int> dp(s.size(), 0);
    	int res = 0;
    	for (int i = 1; i < s.size(); ++i) {
    		if (s[i] == ')') {
    			int index = i - dp[i-1] - 1;
    			if (index >= 0 && s[index] == '(') {
    				dp[i] = dp[i-1] + 2;
    				dp[i] += index > 0 ? dp[index-1] : 0;
    			}
    			res = max(res, dp[i]);
    		}
    	}
    	return res;
    }
};