/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {
    	if (!head) return nullptr;
        ListNode *fast = head, *slow = head, *preSlow = nullptr;
        while (fast && fast->next) {
        	fast = fast->next->next;
        	preSlow = slow;
        	slow = slow->next;
        }
        TreeNode *root = new TreeNode(slow->val);
        if (preSlow) {
        	preSlow->next = nullptr;
        	root->left = sortedListToBST(head);
        	root->right = sortedListToBST(slow->next);
        }
        return root;
    }
};