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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
  		stack<char> st1, st2;
  		ListNode *p = l1, *q = l2, *head = new ListNode(1);
  		while (p) {
  			st1.push(p->val);
  			p = p->next;
  		} 
  		while (q) {
  			st2.push(q->val);
  			q = q->next;
  		}
  		int a, b, c = 0;
  		while (!st1.empty() && !st2.empty()) {
  			a = st1.top();
  			b = st2.top();
  			ListNode *node = new ListNode((a + b + c) % 10);
  			node->next = head->next;
  			head->next = node;
  			c = (a + b + c) / 10;
  			st1.pop();
  			st2.pop();
  		}
  		while (!st1.empty()) {
  			a = st1.top();
  			ListNode *node = new ListNode((a + c) % 10);
  			node->next = head->next;
  			head->next = node;
  			c = (a + c) / 10;
  			st1.pop();
  		}
  		while (!st2.empty()) {
  			a = st2.top();
  			ListNode *node = new ListNode((a + c) % 10);
  			node->next = head->next;
  			head->next = node;
  			c = (a + c) / 10;
  			st2.pop();
  		}
  		return c > 0 ? head : head->next;
    }
};