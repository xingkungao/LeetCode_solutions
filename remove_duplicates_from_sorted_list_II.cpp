/*************************************************************************
  > File Name: remove_duplicates_from_sorted_list_II.cpp
  > Author: lax
  > Mail: xingkungao@gmail.com
  > Created Time: Sun 04 Jan 2015 03:49:34 PM CST
 ************************************************************************/

#include "CPP.h"
#include "utility.h"
using namespace std;

class Solution {
	public:
		ListNode *deleteDuplicates(ListNode *head) {
			if (!head || !head->next)
				return head;
			ListNode *p, *q, *r, *node;
			int cnt, val;
			p = new ListNode(-1);
			p->next = head;
			head = p;

			while (p->next) {
				q = p->next;
				val = q->val;
				cnt = 0;
				while (q && q->val == val) {
					q = q->next;
					cnt++;
				}

				if (cnt >= 2){
					r = p->next;
					p->next = q;
					while (cnt--) {
						node = r;
						r = r->next;
						delete node;
					}
				}
				else {
					p = p->next;
				}
			}

			node = head;
			head = head->next;
			delete node;
			return head;
		}

		void test() {
			ListNode *head;
			while (1) {
				head = createSinglyLinkedList();
				head = deleteDuplicates(head);
				printSinglyLinkedList(head);
				deleteSinglyLinkedList(head);
			}
		}
};

int main() {
	Solution s;
	s.test();
}
