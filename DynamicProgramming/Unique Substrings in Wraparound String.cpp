class Solution {
public:
    int findSubstringInWraproundString(string p) {
        if (p.size() == 0) return 0;
    	vector<int> dp(26, 0);
        dp[p[0] - 'a'] = 1;
        int maxLen = 1, res = 0;
        for (int i = 1; i < p.size(); ++i) {
            if (p[i] - p[i-1] == 1 || p[i] - p[i-1] == -25) {
                ++maxLen;
            } else {
                maxLen = 1;
            }
            dp[p[i] - 'a'] = max(dp[p[i] - 'a'], maxLen);
        }
        for (int i = 0; i < 26; ++i) res += dp[i];
        return res;
    }
};