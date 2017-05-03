struct Node {
	Node* next[2];
	Node() {
		next[0] = next[1] = nullptr;
	}
};

class Solution {
private:
	Node *root;
public:
    int findMaximumXOR(vector<int>& nums) {
        root = new Node();
        for (int n : nums) addNum(n);
        return query(root, root, 31);
    }

	void addNum(int num) {
		Node *cur = root;
		for (int i = 31; i >= 0; --i) {
			int d = (num >> i) & 1;
			if (!cur->next[d]) {
				cur->next[d] = new Node();
			}
			cur = cur->next[d];
		}
	}

	int query(Node *r1, Node *r2, int index) {
		if (!r1 || !r2) return 0;
		int ans = 0;
		if (r1->next[0] && r2->next[1] || r1->next[1] && r2->next[0]) {
			ans = ans | (1 << index);
			ans = ans | max(query(r1->next[0], r2->next[1], index-1), query(r1->next[1], r2->next[0], index-1));
		} else {
			ans = ans | max(query(r1->next[0], r2->next[0], index-1), query(r1->next[1], r2->next[1], index-1));
		}
		
		return ans;
	}
};