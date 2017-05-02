class Trie {
private:
	struct Node {
		char c;
		bool end;
		vector<Node*> children;
		Node(char cc):c(cc), end(false) {}
	};
	Node *root;
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new Node('#');
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Node *cur = root;
        for (char cc : word) {
        	int i = 0;
        	for (; i < cur->children.size(); ++i) {
        		if (cur->children[i]->c == cc) {
        			break;	
        		}
        	}
        	if (i == cur->children.size()) {
        		Node *newNode = new Node(cc);
        		cur->children.push_back(newNode);
        	}
        	cur = cur->children[i];
        }
        cur->end = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node *cur = root;
        for (char cc : word) {
        	int i = 0;
        	for (; i < cur->children.size(); ++i) {
        		if (cur->children[i]->c == cc) {
        			break;	
        		}
        	}
        	if (i == cur->children.size()) {
        		return false;
        	}
        	cur = cur->children[i];
        }
        return cur->end;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node *cur = root;
        for (char cc : prefix) {
        	int i = 0;
        	for (; i < cur->children.size(); ++i) {
        		if (cur->children[i]->c == cc) {
        			break;	
        		}
        	}
        	if (i == cur->children.size()) {
        		return false;
        	}
        	cur = cur->children[i];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */