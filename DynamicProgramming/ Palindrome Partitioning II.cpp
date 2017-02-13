class Solution {
public:
    int minCut(string s) {
    	if (s.size() == 0) return 0;
        vector<int> dp(s.size() + 1, 0);
        for (int i = 0; i <= s.size(); ++i) dp[i] = i-1;
        for (int i = 0; i < s.size(); ++i) {
        	for (int j = 0; i - j >= 0 && i + j < s.size() && s[i-j] == s[i+j]; ++j) {
        		dp[i + j + 1] = min(dp[i + j + 1], dp[i - j] + 1);
        	}
        	for (int j = 1; i - j + 1 >= 0 && i + j < s.size() && s[i-j+1] == s[i+j]; ++j) {
        		dp[i+j+1] = min(dp[i+j+1], dp[i-j+1] + 1);
        	}
        }
        return dp[s.size()];
    }
};