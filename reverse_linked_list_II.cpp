/*************************************************************************
  > File Name: reverse_linked_list_II.cpp
  > Author: lax
  > Mail: xingkungao@gmail.com
  > Created Time: Tue 16 Dec 2014 12:33:04 PM CST
 ************************************************************************/

#include "CPP.h"
#include "utility.h"
using namespace std;
/**
 *
 *  * Definition for singly-linked list.
 struct ListNode {
 int val;
 ListNode *next;
 ListNode(int x) : val(x), next(NULL) {}
 };
 */

class Solution {
	public:
		ListNode *reverseBetween(ListNode *head, int m, int n) {
			int idx, len = 0;
			if (m == n)
				return head;
			ListNode *node = new ListNode(0);
			node->next = head;
			head = node;
			idx = 0;
			while (idx < m - 1) {
				node = node->next;
				idx ++;
			}

			ListNode *p, *q, *r;
			p = node->next;
			q = p->next;
			idx ++;
			while (idx < n) {
				r = q->next;
				q->next = p;
				p = q;
				q = r;
				idx ++;
			}
			node->next->next  = q;
			node->next = p;
			node = head;
			head = head->next;
			delete node;
			return head;
		}
		void test() {
			int a, b;
			ListNode *head = createSinglyLinkedList();
			printSinglyLinkedList(head);
			while (1)  {
				cin >> a >> b;
				printSinglyLinkedList(head = reverseBetween(head, a, b));
			}
		}
};
int main() {
	Solution s;
	s.test();
}
