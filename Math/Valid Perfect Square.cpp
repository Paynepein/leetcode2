class Solution {
public:
    bool isPerfectSquare(int num) {
        int l = 1, r = num;
        while (l <= r) {
        	long mid = l + (r-l>>1);
        	if (mid * mid < long(num)) {
        		l = mid+1;
        	} else if (mid*mid > long(num)) {
        		r = mid-1;
        	} else return true;
        }
        return false;
    }
};