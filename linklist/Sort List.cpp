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
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode *slow = head, *fast = head, *pre = NULL;
        while (fast && fast->next) {
        	fast = fast->next->next;
        	pre = slow;
        	slow = slow->next;
        }
        pre->next = NULL;
        head = sortList(head);
        slow = sortList(slow);
        ListNode *h = new ListNode(0);
        h->next = head;
        pre = slow, fast = h;
        while (pre) {
        	while (fast->next && fast->next->val < pre->val) fast = fast->next;
        	if (!fast->next) {
        		fast->next = pre;
        		break;
        	} else {
        		ListNode *tmp = pre->next;
        		pre->next = fast->next;
        		fast->next = pre;
        		pre = tmp;
        	}
        }
        return h->next;
    }


};