/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> vec1, vec2, *ptr1 = &vec1, *ptr2 = &vec2;
        if (n == 0) return vec1;
        vec1.push_back(new TreeNode(1));
        for (int i = 2;  i <= n; ++i) {
        	ptr2->clear();
        	for (TreeNode *root : *ptr1) {
        		TreeNode *currPtr = root, *newRoot;
        		while (currPtr) {
        			newRoot = makeTree(root, currPtr->val, i);
        			ptr2->push_back(newRoot);
        			currPtr = currPtr->right;
        		}
        		newRoot = makeTree(root, 0, i);
        		currPtr = newRoot;
        		while (currPtr->right) {
        			currPtr = currPtr->right;
        		}
        		currPtr->right = new TreeNode(i);
        		ptr2->push_back(newRoot);
        	}
        	swap(ptr1, ptr2);
        }
        return *ptr1;
    }

    TreeNode* makeTree(TreeNode *root, int cur, int n) {
        if (!root) return root;
    	TreeNode *newRoot = new TreeNode(root->val);
    	newRoot->left = makeTree(root->left, cur, n);
    	newRoot->right = makeTree(root->right, cur, n);
    	if (root->val == cur) {
    		TreeNode *node = new TreeNode(n);
    		node->left = root;
    		newRoot = node;
    	}
    	return newRoot;
    }
};