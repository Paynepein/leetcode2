class Solution {
public:
    int integerReplacement(int n) {
        int ans = 0;
        long long nn = n;
        while (nn > 1) {
        	if (nn % 2 == 0) {
        		nn >>= 1;
        	} else if (nn != 3 && nn & 2) {
        		nn += 1;
        	} else {
        		nn -= 1;
        	}
        	++ans;
        }
        return ans;
    }
};