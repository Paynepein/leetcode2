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
    ListNode* rotateRight(ListNode* head, int k) {
        if (k == 0 || !head || !head->next) return head;
        ListNode *p = head;
        int len = 1;
        while (p->next) {
        	p = p->next;
        	++len;
        }
        p->next = head;
        if (k %= len) {
        	for (int i = 0; i < len-k; ++i) {
        		p = p->next;
        	}
        }
        head = p->next;
        p->next = NULL;
        return head;
    }
};