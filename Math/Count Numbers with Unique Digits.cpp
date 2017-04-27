class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0) return 1;
    	int last = 9, sigh = 10, res = 10;
        for (int i = 2; i <= n; ++i) {
            last = last * (--sigh);
            res += last;
        }
        return res;
    }
};