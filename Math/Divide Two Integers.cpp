class Solution {
public:
    int divide(int dividend, int divisor) {
        if (divisor == 0) exit(1);
        int res = 0;
        if (dividend == INT_MIN) {
        	if (divisor == -1 || divisor == 1) {
        		return divisor == 1 ? INT_MIN : INT_MAX;
        	} else if (divisor == INT_MIN) return 1;
        	dividend += abs(divisor);
        	res = 1;
        }
        bool neg = (dividend ^ divisor) >> 31;
        dividend = abs(dividend);
        divisor = abs(divisor);
        res += divideHelper(dividend, divisor);
        if (neg) {
        	res = ~res + 1;
        }
        return res;
    }

    int divideHelper(unsigned int dividend, unsigned int divisor) {
    	if (dividend < divisor) return 0;
    	unsigned int c = divisor, k = 0;
    	for (; dividend >= c && k < 32; ++k, c <<= 1) {
    		if (dividend - c < divisor) return 1 << k;
    	}
    	c >>= 1;
    	--k;
    	return divideHelper(dividend - c, divisor) + (1 << k);
    }
};