struct Node {
	Node* next[26];
	bool is_word;
	Node(bool end = false):is_word(end) {
		memset(next, 0, sizeof(next));
	}
};

class WordDictionary {
private:
	Node *root;
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new Node();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        Node *cur = root;
        for (char c : word) {
        	if (!cur->next[c - 'a']) {
        		cur->next[c - 'a'] = new Node();
        	}
        	cur = cur->next[c - 'a'];
        }
        cur->is_word = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return searchHelper(word.c_str(), root);
    }
private:
	bool searchHelper(const char word[], Node *rt) {
		if (!rt) return false;
		for (int i = 0; word[i] != '\0'; ++i) {
			if (word[i] == '.') {
				for (int j = 0; j < 26; ++j) {
					if (searchHelper(word+i+1, rt->next[j])) return true;
				}
				return false;
			} else {
				rt = rt->next[word[i] - 'a'];
				if (!rt) return false;
			}
		}
		return rt->is_word;
	}
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * bool param_2 = obj.search(word);
 */