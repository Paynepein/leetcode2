class Solution {
public:
    int mySqrt(int x) {
        if (x < 0) return INT_MIN;
        if (x <= 1) return x == 1;
        int l = 1, r = x / 2;
        while (l <= r) {
        	int mid = (r-l>>1) + l;
        	if (x / mid >= mid) {
        		l = mid+1;
        	} else {
        		r = mid-1;
        	}
        }
        return l-1;
    }
};