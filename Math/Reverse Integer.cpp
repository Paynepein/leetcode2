class Solution {
public:
    int reverse(int x) {
    	if (x == INT_MIN) return 0;
        bool neg = x < 0;
        x = abs(x);
        int ans = 0, sign = 1;
        while (x) {
        	if (INT_MAX / 10 < ans || (INT_MAX / 10 == ans && INT_MAX - ans*10 < x)) return 0;
        	ans = ans * 10 + x % 10;
        	x /= 10;
        }
        return neg ? -1*ans : ans;
    }
};