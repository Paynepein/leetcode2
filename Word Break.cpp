class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;
        for (int i = 1; i <= s.size(); ++i) {
        	for (int j = 0; j < i; ++j) {
        		if (find(wordDict.begin(), wordDict.end(), s.substr(j, i-j)) != wordDict.end()) {
        			dp[i] = dp[j];
        			if (dp[i]) break;
        		}
        	}
        }
        return dp[s.size()];
    }
};