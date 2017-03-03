class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
    	if (word.size() == 0) return true;
    	if (board.size() == 0) return false;
    	int m = board.size(), n = board[0].size();
        for (int i = 0; i < m; ++i) {
        	for (int j = 0; j < n; ++j) {
        		if (board[i][j] == word[0] && existHelper(board, i, j, word, 1)) {
        			return true;
        		}
        	}
        }
        return false;
    }

    bool existHelper(vector<vector<char>>& board, int row, int col, string& word, int index) {
    	if (index == word.size()) return true;
    	char old = board[row][col];
    	board[row][col] = '#';
    	bool res = false;
    	int m = board.size(), n = board[0].size();
    	if (row > 0 && board[row-1][col] == word[index]) res = res || existHelper(board, row-1, col, word, index+1);
    	if (col > 0 && board[row][col-1] == word[index]) res = res || existHelper(board, row, col-1, word, index+1);
    	if (row < m-1 && board[row+1][col] == word[index]) res = res || existHelper(board, row+1, col, word, index+1);
    	if (col < n-1 && board[row][col+1] == word[index]) res = res || existHelper(board, row, col+1, word, index+1);
    	board[row][col] = old;
    	return res;
    }
};