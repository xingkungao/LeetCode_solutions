/*************************************************************************
  > File Name: intersection_of_two_linked_lists.cpp
  > Author: lax
  > Mail: xingkungao@gmail.com
  > Created Time: Wed 24 Dec 2014 10:25:50 PM CST
 ************************************************************************/

#include "CPP.h"
#include "utility.h"
using namespace std;

class Solution {
	public:
		ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
			if (!headA || !headB)
				return 0;
			ListNode *p, *q, *tail;
			p = headA;
			while (p->next) {
				p = p->next;
			}
			tail = p;
			p->next = headB;

			p = q = headA;
			while (q && q->next) {
				p = p->next;
				q = q->next->next;
				if (p == q) {
					q = headA;
					while (p != q) {
						p = p->next;
						q = q->next;
					}
					tail->next = 0;
					return p;
				}
			}
			tail->next = 0;
			return 0;
		}
		void test() {
			ListNode *headA = new ListNode(1);
			headA->next = new ListNode(2);
			ListNode *headB = new ListNode(1);
			headB->next = new ListNode(2);
			headB->next->next = new ListNode(3);
			ListNode *c = new ListNode(4);
			c->next = new ListNode(5);
			headA->next->next = c;
			headB->next->next->next = c;
			ListNode *f =  getIntersectionNode(headA, headB);
			cout << f->val << endl;

		}
};

int main() {
	Solution s;
	s.test();
}
