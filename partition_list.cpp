/*************************************************************************
  > File Name: partition_list.cpp
  > Author: lax
  > Mail: xingkungao@gmail.com
  > Created Time: Tue 16 Dec 2014 03:55:53 PM CST
 ************************************************************************/

#include "CPP.h"
#include "utility.h"

class Solution {
	public:
		ListNode *partition(ListNode *head, int x) {
			ListNode *tail, *node = new ListNode(-1);
			node->next = head;
			head = node;

			ListNode *p, *q;
			tail = head;
			while (tail->next) {
				tail = tail->next;
			}

			node = new ListNode(-1);
			tail->next = node;
			tail = tail->next;
			p = head;
			while (p->next) {
				if (p->next == node) {
					p->next = node->next;
					delete node;
					break;
				}
				if (p->next->val < x)
					p = p->next;
				else {
					tail->next = p->next;
					tail = tail->next;
					p->next = p->next->next;
					tail->next = 0;
				}
			}
			p = head;
			head = head->next;
			delete p;
			return head;

		}
		int length(ListNode *head) {
			int len = 0;
			while (head) {
				head = head ->next;
				len++;
			}
			return len;
		}
		void test() {
			ListNode *head;
			int x;
			while (1) {
				head = createSinglyLinkedList();
				cin >> x;
				head = partition(head, x);
				printSinglyLinkedList(head);
				deleteSinglyLinkedList(head);
			}
		}
};

int main() {
	Solution s;
	s.test();
}
