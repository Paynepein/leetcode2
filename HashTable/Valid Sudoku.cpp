class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int used1[9][9], used2[9][9], used3[9][9];
        memset(used1, 0, sizeof(used1));
        memset(used2, 0, sizeof(used2));
        memset(used3, 0, sizeof(used3));
        int m = board.size(), n = board[0].size();
        for (int i = 0; i < m; ++i) {
        	for (int j = 0; j < n; ++j) {
        		if (board[i][j] != '.') {
        			int k = 3 * (i / 3) + j / 3, num = board[i][j] - 1 - '0';	
        			if (used1[i][num] == 1 || used2[j][num] == 1 || used3[k][num] == 1) return false;
        			used1[i][num] = used2[j][num] = used3[k][num] = 1;
        		}
        	}
        }
        return true;
    }
};