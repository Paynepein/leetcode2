class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n,0));
        int i = 0, j = 0, k = 1, turn = 0;
        while (k <= n*n) {
        	while (j < n - turn) {
        		res[i][j++] = k++;
        	}
        	if (k > n*n) return res;
        	++i, --j;
        	while (i < n - turn) {
        		res[i++][j] = k++;
        	}
        	if (k > n*n) return res;
        	--i, --j;
        	while (j >= turn) {
        		res[i][j--] = k++;
        	}
        	if (k > n*n) return res;
        	--i, ++j;
        	while (i > turn) {
        		res[i--][j] = k++;
        	}
        	++i, ++j;
        	++turn;
        }
        return res;
    }
};