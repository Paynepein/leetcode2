class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
    	if (x + y < z) return false;
    	if (x == z || y == z || x+y == z) return true;
        return z % gcd(x, y) == 0;
    }

    int gcd(int a, int b) {
    	if (a < b) return gcd(b, a);
    	while (b != 0) {
    		int t = a % b;
    		a = b;
    		b = t;
    	}
    	return a;
    }
};