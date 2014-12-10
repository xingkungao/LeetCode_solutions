/*************************************************************************
  > File Name: remove_nth_node_from_end_of_list.cpp
  > Author: lax
  > Mail: xingkungao@gmail.com
  > Created Time: Wed 10 Dec 2014 04:01:25 PM CST
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cassert>
using namespace std;
/**
 *
 *  * Definition for singly-linked list.
 */
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
	public:
		/* traverse one pass */
		ListNode *removeNthFromEnd(ListNode *head, int n) {
			ListNode *node = new ListNode(0);
			node->next = head;
			head = node;
			ListNode *p = head, *q = head;
			for (int i = 0; i < n; i++)
				p = p->next;
			while (p->next) {
				q = q->next;
				p = p->next;
			}
			p = q->next;
			q->next = q->next->next;
			delete p;
			p = head;
			delete p;
			head = head->next;
			return head;
		}
		void print(ListNode *head) {
			while (head) {
				cout << head->val << " ";
				head = head ->next;
			}
			cout << endl;
		}
		ListNode *create() {
			ListNode *head = new ListNode(1);
			head->next = new ListNode(2);
			head->next->next = new ListNode(3);
			head->next->next->next = new ListNode(4);
			head->next->next->next->next = new ListNode(5);
			return head;
		}
		void clear(ListNode *h) {
			ListNode *p;
			while (h) {
				p = h;
				h = h->next;
				delete p;
			}
		}
		void test() {
			for (int i = 1; i <= 5; i++) {
				removeNthFromEnd(create(), i);
			}
		}


};

int main() {
	Solution s;
	s.test();
}

