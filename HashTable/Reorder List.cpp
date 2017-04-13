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
    void reorderList(ListNode* head) {
    	if (!head || !head->next) return;
        ListNode *mid = head, *fast = head;
        while (fast && fast->next) {
        	fast = fast->next->next;
        	mid = mid->next;
        }
        fast = mid->next;
        ListNode *next, *fh = nullptr;
        while (fast) {
        	next = fast->next;
        	fast->next = fh;
        	mid->next = fast;
        	fh = fast;
        	fast = next;
        }
        fast = head;
        while (fh) {
        	mid->next = fh->next;
        	fh->next = fast->next;
        	fast->next = fh;
        	fh = mid->next;
        	fast = fast->next->next;
        }
        return;
    }
};