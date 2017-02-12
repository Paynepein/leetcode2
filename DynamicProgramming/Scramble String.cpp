class Solution {
public:
    bool isScramble(string s1, string s2) {
    	if (s1.size() != s2.size()) return false;
    	if (s1.size() == 0) return true;
        unordered_map<string, bool> dp;
        return isScrambleHelper(s1, s2, dp);
    }

    bool isScrambleHelper(string s1, string s2, unordered_map<string, bool>& dp) {
    	if (dp.find(s1+s2) != dp.end()) return dp[s1+s2];
    	bool res = false;
    	if (s1 == s2) res = true;
    	else if (s1.size() == 1) res = s1 == s2;
    	else {
    		for (int len = 1; len < s1.size(); ++len) {
    			if (isScrambleHelper(s1.substr(0, len), s2.substr(0, len), dp) && isScrambleHelper(s1.substr(len), s2.substr(len), dp)) {
    				res = true;
    				break;
    			}
    			else if (isScrambleHelper(s1.substr(0, len), s2.substr(s2.size() - len), dp) && isScrambleHelper(s1.substr(len), s2.substr(0, s2.size() - len), dp)) {
    				res = true;
    				break;
    			}
    		}
    	}
    	dp[s1+s2] = res;
    	return res;
    }
};