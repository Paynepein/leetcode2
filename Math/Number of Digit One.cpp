class Solution {
	int nn, l, num[32], dp[32][10];
public:
	void init(int n) {
		memset(dp, -1, sizeof(dp));
		l = 0, nn = n;
		while (n) {
			num[l++] = n % 10;
			n /= 10;
		}
	}

    int countDigitOne(int n) {
    	if (n <= 0) return 0;
    	init(n);
    	return dfs(0, l-1, 1);
    }

    int dfs(int pre, int pos, bool limit) {
    	if (pos == -1) return 0;
    	if (!limit && dp[pos][pre] != -1) return dp[pos][pre];
    	int ans = 0;
    	int mx = limit ? num[pos] : 9;
    	for (int i = 0; i <= mx; ++i) {
    		ans += dfs(i, pos-1, limit && i == mx);
    	}
    	if (mx > 1) {
    		ans += pow(10, pos);
    	} else if (mx == 1) {
    	    ans += nn % int(pow(10, pos)) + 1;
    	}
    	if (!limit) dp[pos][pre] = ans;
    	return ans;
    }
};