/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode *slow = head, *fast = head, *pre = NULL, *next;
        while (fast && fast->next) {
        	fast = fast->next->next;
        	next = slow->next;
        	slow->next = pre;
        	pre = slow;
        	slow = next;
        }
        if (fast) slow = slow->next;
        while (slow) {
        	if (slow->val != pre->val) return false;
        	slow = slow->next;
        	pre = pre->next;
        }
        return true;
    }
};