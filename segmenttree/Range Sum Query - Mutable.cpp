class NumArray {
private:
	int *tree;
	int n;

	void build(int root, int l, int r, vector<int>& nums) {
		if (l == r) {
			tree[root] = nums[l];
			return;
		}
		int mid = l + r >> 1;
		build(root*2+1, l, mid, nums);
		build(root*2+2, mid+1, r, nums);
		tree[root] = tree[root*2+1] + tree[root*2+2];
	}

	int query(int root, int l, int r, int i, int j) {
		if (l > j || r < i || i > j) return 0;
		if (l >= i && r <= j) return tree[root];
		int ans = 0;
		int mid = l + r >> 1;
		if (l <= j && mid >= i) ans += query(root*2+1, l, mid, i, j);
		if (mid+1 <= j && r >= i) ans += query(root*2+2, mid+1, r, i, j);
		return ans;
	}

	void update(int root, int l, int r, int index, int value) {
		if (l == r) {
			if (l == index) tree[root] = value;
			return;
		}
		int mid = l + r >> 1;
		if (l <= index && mid >= index) update(root*2+1, l, mid, index, value);
		else if (mid+1 <= index && r >= index) update(root*2+2, mid+1, r, index, value);
		tree[root] = tree[root*2+1] + tree[root*2+2];
	}

public:
    NumArray(vector<int> nums) {
    	if (nums.size() > 0) {
    		n = 1;
    		while (n < nums.size()) {
    			n <<= 1;
    		}
        	tree = new int[n*2];
        	build(0, 0, n-1, nums);
    	}
    }
    
    void update(int i, int val) {
        update(0, 0, n-1, i, val);
    }
    
    int sumRange(int i, int j) {
        return query(0, 0, n-1, i, j);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(i,val);
 * int param_2 = obj.sumRange(i,j);
 */