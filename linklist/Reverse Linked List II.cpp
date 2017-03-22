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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (m == n || !head || !head->next) return head;
        ListNode *fake = new ListNode(0), *pm = fake;
        fake->next = head;
        for (int i = 0; i < m-1; ++i) pm = pm->next;
        ListNode *start = pm->next, *next = start->next;
    	for (int i = 0; i < n-m; ++i) {
    		start->next = next->next;
    		next->next = pm->next;
    		pm->next = next;
    		next = start->next;
    	}
    	return fake->next;
    }
};