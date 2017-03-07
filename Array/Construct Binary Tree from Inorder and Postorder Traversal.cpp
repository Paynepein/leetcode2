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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return buildTreeHelper(inorder, 0, postorder, 0, inorder.size());
    }

    TreeNode* buildTreeHelper(vector<int>& inorder, int l1, vector<int>& postorder, int l2, int len) {
    	if (len <= 0) return nullptr;
    	TreeNode *root = new TreeNode(postorder[l2 + len - 1]);
    	int count = 0;
    	while (l1 + count < inorder.size() && inorder[l1 + count] != root->val) ++count;
    	root->left = buildTreeHelper(inorder, l1, postorder, l2, count);
    	root->right = buildTreeHelper(inorder, l1 + count + 1, postorder, l2 + count, len-count-1);
    	return root;
    }
};