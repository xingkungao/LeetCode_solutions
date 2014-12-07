/*************************************************************************
  > File Name: merge_two_sorted_lists.cpp
  > Author: lax
  > Mail: xingkungao@gmail.com
  > Created Time: Sun 07 Dec 2014 12:39:30 PM CST
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
		ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
			ListNode *head = 0, *tail;
			ListNode *p;
			while (l1 && l2) {
				p = l1->val < l2->val ? l1 : l2;
				if (!head) head = tail = p;
				else {
					tail->next = new ListNode(p->val);
					tail = tail->next;
				}
				if (p == l1)
					l1 = l1->next;
				else 
					l2 = l2->next;
			}

			p = l1 ? l1 : l2;
			while (p) {
				if (!head) head = tail = p; 
				else {
					tail->next = new ListNode(p->val);
					tail = tail->next;
				}
				p = p->next;
			}
			return head;
		}
		void print(ListNode* head) {
			while (head) {
				cout << head->val << " ";
				head = head->next;
			}
			cout << endl;
		}
		void test() {
			ListNode *a = new ListNode(2);
			ListNode *b = new ListNode(1);
			print(mergeTwoLists(a, b));
		}
};
int main() {
	Solution s;
	s.test();
}

