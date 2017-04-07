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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int len1 = 0, len2 = 0;
        ListNode *p1 = headA, *p2 = headB;
        while (p1) {
        	++len1;
        	p1 = p1->next;
        }
        while (p2) {
        	++len2;
        	p2 = p2->next;
        }
        while (len1 < len2--) {
        	headB = headB->next;
        }
        ++len2;
        while (len2 < len1--) {
        	headA = headA->next;
        }
        while (headA != headB) {
        	headA = headA->next;
        	headB = headB->next;
        }
        return headA;
    }
};