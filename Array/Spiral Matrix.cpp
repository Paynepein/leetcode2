class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if (matrix.size() == 0) return res;
        int m = matrix.size(), n = matrix[0].size();
        int i = 0, j = 0, k = 0, turn = 0;
        res.resize(m * n);
        while (k < m*n) {
        	while (j < n - turn) {
        		res[k++] = matrix[i][j++];
        	}
        	if (k == m*n) return res;
        	++i, --j;
        	while (i < m - turn) {
        		res[k++] = matrix[i++][j];
        	}
        	if (k == m*n) return res;
        	--i, --j;
        	while (j >= turn) {
        		res[k++] = matrix[i][j--];
        	}
        	if (k == m*n) return res;
        	--i, ++j;
        	while (i > turn) {
        		res[k++] = matrix[i--][j];
        	}
        	if (k == m*n) return res;
        	++i, ++j;
        	++turn;
        }
        return res;
    }
};