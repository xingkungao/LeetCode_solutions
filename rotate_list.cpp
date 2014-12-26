/*************************************************************************
  > File Name: rotate_list.cpp
  > Author: lax
  > Mail: xingkungao@gmail.com
  > Created Time: Fri 26 Dec 2014 09:30:21 PM CST
 ************************************************************************/

#include "CPP.h"
#include "utility.h"
using namespace std;

class Solution {
	public:
		ListNode *rotateRight(ListNode *head, int k) {
			if (!head)
				return head;
			int len = getLength(head);
			k = k % len;
			if (!k)
				return head;
			ListNode *p = head, *q;
			for (int i = 0; i < len - k - 1; i++)
				p = p->next;
			q = p->next;
			while (q->next) 
				q = q->next;
			q->next = head;
			head = p->next;
			p->next = 0;
			return head;

		}
		int getLength(ListNode *head) {
			int len = 0;
			while (head) {
				len++;
				head = head->next;
			}
			return len;
		}
		void test() {
			int x;
			while (1) {
				cout << "input list\n";
				ListNode *head = createSinglyLinkedList();
				cout << "input rotate number\n";
				cin >> x;
				head = rotateRight(head, x);
				printSinglyLinkedList(head);
				deleteSinglyLinkedList(head);
			}
		}
};

int main() {
	Solution s;
	s.test();
}
