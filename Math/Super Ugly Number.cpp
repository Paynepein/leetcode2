class Solution {
	int num[1000010], index[110];
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int idx = 0;
        num[0] = 1;
        --n;
        memset(index, 0, sizeof(index));
        while (idx++ < n) {
        	num[idx] = INT_MAX;
        	for (int i = 0; i < primes.size(); ++i) {
        		num[idx] = min(num[index[i]] * primes[i], num[idx]);
        	}
        	for (int i = 0; i < primes.size(); ++i) {
        		if (num[index[i]] * primes[i] == num[idx]) ++index[i];
        	}
        }
        return num[n];
    }
};