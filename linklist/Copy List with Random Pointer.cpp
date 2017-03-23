/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
    	if (!head) return nullptr;
        RandomListNode *next, *p = head;
        while (p) {
        	RandomListNode *copy = new RandomListNode(p->label);
        	next = p->next;
        	p->next = copy;
        	copy->next = next;
        	p = next;
        }
        p = head;
        while (p) {
        	if (p->random) {
        		p->next->random = p->random->next;
        	}
        	p = p->next->next;
        }
        RandomListNode *nhead = head->next;
        next = nhead;
        p = head->next->next;
        head->next = p;
        while (p) {
        	next->next = p->next;
        	next = next->next;
        	p->next = next->next;
        	p = p->next;
        }
        return nhead;
    }
};