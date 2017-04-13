class Solution {
public:
    int countPrimes(int n) {
  		vector<bool> visited(n, 0);
  		int count = 0;
  		for (int i = 2; i < n; ++i) {
  			if (!visited[i]) {
  				++count;
  				int j = i;
  				while (j < n) {
  					visited[j] = 1;
  					j += i;
  				}
  			}
  		}      
  		return count;
    }
};