/*************************************************************************
  > File Name: swap_nodes_in_pairs.cpp
  > Author: lax
  > Mail: xingkungao@gmail.com
  > Created Time: Sat 27 Dec 2014 12:31:05 AM CST
 ************************************************************************/

#include "CPP.h"
#include "utility.h"
using namespace std;

class Solution {
	public:
		ListNode *swapPairs(ListNode *head) {
			if (!head || !head->next)
				return head;
			ListNode *p, *q, *r;
			p = new ListNode(0);
			p->next = head;
			head = p;

			while (p && p->next && p->next->next) {
				q = p->next;
				r = q->next;
				if (r) {
					q->next = r->next;
					r->next = q;
					p->next = r;

					p = q; 
				}
			}
			p = head;
			head = head->next;
			delete p;
			return head;
		}
		void test() {
			while (1) {
				ListNode *head = createSinglyLinkedList();
				head = swapPairs(head);
				printSinglyLinkedList(head);
				deleteSinglyLinkedList(head);
			}
		}
};

int main() {
	Solution s;
	s.test();
}
