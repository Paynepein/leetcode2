class Solution {
public:
    bool isMatch(string s, string p) {
    	if (s.size() == 0) return isEmpty(p);
    	int si = 0, pi = 0;
    	while (si < s.size()) {
    		if (pi == p.size()) return false;
    		else if (pi + 1 == p.size()) return (p[pi] == '.' || s[si] == p[pi]) && si + 1 == s.size();
    		else if (p[pi] == '.' || s[si] == p[pi]) {
    			if (p[pi + 1] == '*') {
    				int i = si;
    				for (; i < s.size(); ++i) {
    					if (s[i] == s[si] || p[pi] == '.') {
    						if (isMatch(s.substr(i), p.substr(pi+2))) return true;
    					} else {
    						break;
    					}
    				}
    				si = i;
    				pi += 2;
    			} else {
    				++si;
    				++pi;
    			}
    		} else if (p[pi+1] == '*') {
    			pi += 2;
    		} else {
    			return false;
    		}
    	}
    	return isEmpty(p.substr(pi));
    }

    bool isEmpty(string p) {
    	for (int i = 0; i < p.size(); i += 2) {
    		if (p[i] == '*' || i + 1 == p.size() || p[i+1] != '*') return false;
    	}
    	return true;
    }
};