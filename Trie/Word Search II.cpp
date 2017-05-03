struct Node {
	Node* next[26];
	bool is_world;
	Node():is_world(false) {
		memset(next, 0, sizeof(next));
	}
};

class Solution {
private:
	int m, n;
	Node *root;
	vector<string> res;

	void buildTrieTree(vector<string>& words) {
		root = new Node();
		for (string word : words) {
			addWord(word);	
		}
	}

	void addWord(string word) {
		Node *cur = root;
		for (char c : word) {
			if (!cur->next[c - 'a']) {
				cur->next[c - 'a'] = new Node();
			}
			cur = cur->next[c - 'a'];
		}
		cur->is_world = true;
	}

	void query(vector<vector<char>>& board, int row, int col, Node *root, string word) {
		if (!root) return;
		Node *cur = root->next[board[row][col] - 'a'];
		word += board[row][col];
		if (cur) {
			if (cur->is_world) {
				res.push_back(word);
				cur->is_world = false;
			}
			char old = board[row][col];
			board[row][col] = '#';
			if (row < m-1 && board[row+1][col] != '#') query(board, row+1, col, cur, word);
			if (row > 0 && board[row-1][col] != '#') query(board, row-1, col, cur, word);
			if (col < n-1 && board[row][col+1] != '#') query(board, row, col+1, cur, word);
			if (col > 0 && board[row][col-1] != '#') query(board, row, col-1, cur, word);
			board[row][col] = old;
		}
	}

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        buildTrieTree(words);
        m = board.size(), n = board[0].size();
        for (int i = 0; i < m; ++i) {
        	for (int j = 0; j < n; ++j) {
        		query(board, i, j, root, "");
        	}
        }
        return res;
    }
};