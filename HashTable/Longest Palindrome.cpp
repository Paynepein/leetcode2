class Solution {
public:
    int longestPalindrome(string s) {
        int single = 0, res = 0;
        vector<int> visit(256, 0);
        for (char c : s) {
        	if (visit[c]) {
        		visit[c] = 0;
        		res += 2;
        		--single;
        	} else {
        		visit[c] = 1;
        		++single;
        	}
        }
        return res + (single > 0);
    }
};