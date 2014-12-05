/*************************************************************************
  > File Name: add_two_numbers.cpp
  > Author: lax
  > Mail: xingkungao@gmail.com
  > Created Time: Thu 04 Dec 2014 05:17:35 PM CST
 ************************************************************************/

#include <iostream>
#include <cstdio>
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
		ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
			int a, b, c = 0;
			ListNode *p = l1, *q = l2, *head = 0, *t;
			while (l1 && l2) {
				a = l1->val;
				b = l2->val;
				ListNode *n = new ListNode((c + a + b) % 10);
				c = (c + a + b) / 10;
				if (!head)
					head = t = n;
				else  {
					t->next = n;
					t = t->next;
				}
				l1 = l1->next;
				l2 = l2->next;
			}
			if (l1 || l2) {
				ListNode *l = l1 ? l1 : l2;
				while (l) {
					ListNode *n = new ListNode((c + l->val) % 10);
					c = (c + l->val) / 10;
					if (!head) head = t = n;
					else {
						t->next = n;
						t = t->next;
					}
					l = l->next;
				}
			}
			if (c) 
				t->next = new ListNode(c);
			return head; 
		}
		ListNode* reverseList(ListNode* l) {
			if (!l)
				return 0;
			ListNode *p = l, *q = l->next, *r;
			while (q) {
				r = q->next;
				q->next = p;
				p = q;
				q = r;
			}
			l->next = 0;
			return p;
		}
		void print(ListNode *l) {
			while (l) {
				cout << l->val << " ";
				l = l->next;
			}
			cout << endl;
		}
		ListNode* create() {
			int x;
			ListNode *l = 0, *t;
			while (cin >> x && x > 0) {
				if (!l)
					l = t = new ListNode(x);
				else {
					t->next = new ListNode(x);
					t = t->next;
				}
			}
			return l;
		}
		void clear(ListNode *l) {
			ListNode* p;
			while (l) {
				p = l;
				l = l->next;
				delete p;
			}
		}
		void test() {
			ListNode *l1 = create();
			ListNode *l2 = create();
			print(l1);
			print(l2);
			ListNode *l = addTwoNumbers(l1, l2);
			print(l);
			clear(l1);
			clear(l2);
			clear(l);
		}
};
int main() {
	Solution s;
	s.test();
}

