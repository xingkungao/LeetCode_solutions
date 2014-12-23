/*************************************************************************
  > File Name: reorder_list.cpp
  > Author: lax
  > Mail: xingkungao@gmail.com
  > Created Time: Tue 23 Dec 2014 01:34:05 PM CST
 ************************************************************************/

#include "CPP.h"
#include "utility.h"
using namespace std;

class Solution {
	public:
		void reorderList(ListNode *head) {
			if (!head || !head->next)
				return;
			ListNode *p = head, *q = head, *r;
			/** notice the condition variables, q->next->next is used to 
			 * make sure p points to floor(n) (0 based) when the loop terminates.
			 */
			while (q && q->next && q->next->next) {
				p = p->next;
				q = q->next->next;
			}
			q = p->next;
			p->next = 0;
			p = 0;
			while (q) {
				r = q->next;
				q->next = p;
				p = q; 
				q = r;
			}

			q = head;
			ListNode *s = q;
			q = q->next;
			while (p && q) {
				s->next = p;
				s = s->next;
				p = p->next;

				s->next = q;
				s = s->next;
				q = q->next;
			}
			if (p)
				s->next = p;
			else if (q) 
				s->next = q;
		}
		void test() {
			ListNode * head = createSinglyLinkedList();
			printSinglyLinkedList(head);
			reorderList(head);
			printSinglyLinkedList(head);
			deleteSinglyLinkedList(head);
		}
};

int main() {
	Solution s;
	s.test();
}

