class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
    	int m = board.size(), n = board[0].size();
  		int used1[9][9], used2[9][9], used3[9][9];
        memset(used1, 0, sizeof(used1));
        memset(used2, 0, sizeof(used2));
        memset(used3, 0, sizeof(used3));
        for (int i = 0; i < m; ++i) {
        	for (int j = 0; j < n; ++j) {
        		if (board[i][j] != '.') {
        			int k = 3 * (i / 3) + j / 3, num = board[i][j] - '0' - 1;
        			used1[i][num] = used2[j][num] = used3[k][num] = 1;		
        		}		
        	}
        }
        solveSudokuHelper(board, 0, 0, used1, used2, used3);
    }

    bool solveSudokuHelper(vector<vector<char>>& board, int i, int j, int used1[][9], int used2[][9], int used3[][9]) {
        int k = 3 * (i / 3) + j / 3, m = board.size(), n = board[0].size();
    	if (board[i][j] == '.') {
    		for (int num = 0; num < 9; ++num) {
    			if (used1[i][num] == 0 && used2[j][num] == 0 && used3[k][num] == 0) {
    				board[i][j] = num + '0' + 1;
    				used1[i][num] = used2[j][num] = used3[k][num] = 1;
    				int nextI = j == n-1 ? i+1 : i, nextJ = j == n-1 ? 0 : j+1;
    				if (nextI == m || solveSudokuHelper(board, nextI, nextJ, used1, used2, used3)) return true;
    				board[i][j] = '.';
    				used1[i][num] = used2[j][num] = used3[k][num] = 0;
    			}
    		}
    	} else {
    		int nextI = j == n-1 ? i+1 : i, nextJ = j == n-1 ? 0 : j+1;
    		return (nextI == m || solveSudokuHelper(board, nextI, nextJ, used1, used2, used3));
    	}
    	return false;
    }
};