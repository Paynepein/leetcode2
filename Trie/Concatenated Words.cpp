struct Node {
	Node* next[26];
	bool is_word;
	Node():is_word(false) {
		memset(next, 0, sizeof(next));
	}
};

class Solution {
private:
	Node *root;
	vector<string> res;
public:

	void addWord(string word) {
		if (word.size() == 0) return;
		Node *cur = root;
		for (char c : word) {
			if (!cur->next[c - 'a']) cur->next[c - 'a'] = new Node();
			cur = cur->next[c - 'a'];
		}
		cur->is_word = true;
	}

	bool find(const char *word, Node *rt, int ct) {
		if (!word) return ct > 1;
		for (int i = 0; word[i] != '\0'; ++i) {
			if (!rt->next[word[i] - 'a']) return false;
			if (rt->next[word[i] - 'a']->is_word && word[i+1] && find(word+i+1, root, ct+1)) return true;
			rt = rt->next[word[i] - 'a'];
		}
		return rt->is_word && ct > 1;
	}

    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        root = new Node();
        sort(words.begin(), words.end(), [](string s1, string s2) -> bool {
        	return s1.size() < s2.size();
        });
        for (string word : words) {
        	if (word.size() > 0 && find(word.c_str(), root, 1)) res.push_back(word);
        	addWord(word);
        }
        return res;
    }
};

class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        vector<string> res;
        unordered_set<string> dic(words.begin(), words.end());
        for (string word : words) {
        	vector<int> dp(word.size()+1, 0);
        	dp[0] = 1;
        	for (int i = 0; i < word.size(); ++i) {
        		if (dp[i] == 0) continue;
        		for (int j = i+1; j <= word.size(); ++j) {
        			if (j - i < word.size() && dic.count(word.substr(i, j-i))) dp[j] = 1;
        		}
        		if (dp.back()) {
        			res.push_back(word);
        			break;
        		}
        	}
        }
        return res;
    }
};