class Solution {
public:
    int superPow(int a, vector<int>& b) {
    	if (b.empty()) return 1;
  		int last = b.back();
  		b.pop_back();
  		return superPowHelper(superPow(a, b) % 1337, 10) * superPowHelper(a % 1337, last) % 1337;
    }

    int superPowHelper(int a, int num) {
    	int ans = 1;
    	while (num > 0) {
    		if (num % 2) ans = ans * a % 1337;
    		a = a * a % 1337;
    		num >>= 1;
    	}
    	return ans;
    }
};