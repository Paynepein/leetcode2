class Solution {
public:
    int numDecodings(string s) {
    	if (s.size() == 0 || s[0] == '0') return 0;
    	if (s.size() == 1) return s[0] != '0';
        int pre = 1, cur = 1;
        for (int i = 1; i < s.size(); ++i) {
        	if (s[i] == '0') {
        		if (s[i-1] == '0' || s[i-1] >= '3') return 0;
        		swap(pre, cur);
        	} else if (s[i-1] == '1' || s[i-1] == '2' && s[i] <= '6') {
        		cur += pre;
        		pre = cur - pre;
        	} else {
        		pre = cur;
        	}
        }
        return cur;
    }
};