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
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode *p = reverseList(head->next), *q = p;
        head->next = NULL;
        while (q->next) q = q->next;
        q->next = head;
        return p;
    }
};


class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *p = NULL, *next;
        while (head) {
        	next = head->next;
        	head->next = p;
        	p = head;
        	head = next;
        }
        return p;
    }
};