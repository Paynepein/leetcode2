class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<vector<string>> dp(s.size()+1, vector<string>());
        dp[0].push_back("");
        for (int i = 1; i <= s.size(); ++i) {
        	for (int j = 0; j < i; ++j) {
        		if (find(wordDict.begin(), wordDict.end(), s.substr(j, i-j)) != wordDict.end()) {
        			for (string sentence : dp[j]) {
        				dp[i].push_back(sentence + " " + s.substr(j, i-j));
        			}
        		}
        	}
        }
        for (string& sentence : dp[s.size()]) {
        	sentence = sentence.substr(1);
        }
        return dp[s.size()];
    }
};