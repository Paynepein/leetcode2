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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTreeHelper(preorder, 0, inorder, 0, preorder.size());
    }

    TreeNode* buildTreeHelper(vector<int>& preorder, int l1, vector<int>& inorder, int l2, int len) {
    	if (len <= 0) return nullptr;
    	TreeNode *root = new TreeNode(preorder[l1]);
    	int count = 0;
    	while (count < len && inorder[l2 + count] != preorder[l1]) ++count;
    	root->left = buildTreeHelper(preorder, l1+1, inorder, l2, count);
        root->right = buildTreeHelper(preorder, l1 + count + 1, inorder, l2 + count + 1, len-count-1);
    	return root;
    }
};