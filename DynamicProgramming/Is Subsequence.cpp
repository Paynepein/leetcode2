class Solution {
public:
    bool isSubsequence(string s, string t) {
    	if (s.size() == 0) return true;
    	if (t.size() == 0) return false;
    	int si = 0, ti = 0;
        for (; si < s.size(); ++si, ++ti) {
        	while (ti < t.size() && s[si] != t[ti]) ++ti;
        	if (ti == t.size()) return false;
        }
        return true;
    }
};