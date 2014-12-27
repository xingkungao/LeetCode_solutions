/*************************************************************************
  > File Name: reverse_nodes_in_k_group.cpp
  > Author: lax
  > Mail: xingkungao@gmail.com
  > Created Time: Sat 27 Dec 2014 08:58:25 PM CST
 ************************************************************************/

#include "CPP.h"
#include "utility.h"
using namespace std;
class Solution {
	public:
		ListNode *reverseKGroup(ListNode *head, int k) {
			int len = getLen(head);
			if (!len || k > len || k == 1)
				return head;
			int cnt = len / k;
			ListNode *p, *q, *r, *s, *t;
			p = new ListNode(0);
			p->next = head;
			head = p;

			s = head;
			for (int i = 0; i < cnt; i++) {
				int sum = 1;
				p = s->next;
				q = p->next;
				while (sum < k) {
					r = q->next;
					q->next = p;
					p = q;
					q = r;
					sum++;
				}
				s->next->next = q;
				r = s->next;
				s->next = p;
				s = r;
			}
			p = head;
			delete p;
			head = head->next;
			return head;
		}
		int getLen(ListNode *h) {
			int len = 0;
			while (h) {
				len ++;
				h = h->next;
			}
			return len;
		}
		void test() {
			ListNode *head;
			int k;
			while (1) {
				ListNode *head = createSinglyLinkedList();
				cin >> k;
				head = reverseKGroup(head, k);
				printSinglyLinkedList(head);
				deleteSinglyLinkedList(head);
			}
		}

};


int main() {
	Solution s;
	s.test();
}
