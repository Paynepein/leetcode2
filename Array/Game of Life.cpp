class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
    	if (board.size() == 0) return;
    	int m = board.size(), n = board[0].size();
        for (int i = 0; i < m; ++i) {
        	for (int j = 0; j < n; ++j) {
        		board[i][j] = getLife(board, i, j);
        	}
        }
        for (int i = 0; i < m; ++i) {
        	for (int j = 0; j < n; ++j) {
        		board[i][j] = board[i][j] & 1;
        	}
        }
    }

    int getLife(vector<vector<int>>& board, int row, int col) {
    	int m = board.size(), n = board[0].size();
    	int alive = 0, dead = 0, res = 0;
    	vector<vector<int>> direct = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
    	for (auto vec : direct) {
    		int i = row + vec[0], j = col + vec[1];
    		if (i >= 0 && i < m && j >= 0 && j < n) {
    			if (board[i][j] == 0 || board[i][j] == 3) ++dead;
    			else ++alive;
    		}
    	}
    	if (board[row][col] == 1) {
    		if (alive < 2 || alive > 3) res = 2;
    		else res = 1;	
    	} else if (alive == 3) {
    		res = 3;
    	}
    	return res;
    }
};