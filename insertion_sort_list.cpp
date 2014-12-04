/*************************************************************************
  > File Name: insertion_sort_list.cpp
  > Author: lax
  > Mail: xingkungao@gmail.com
  > Created Time: Tue 02 Dec 2014 11:43:38 PM CST
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cassert>
using namespace std;
/**
 *  * Definition for singly-linked list.
 */
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
	public:
		ListNode *insertionSortList(ListNode *head) {
			ListNode* node = new ListNode(0);
			node->next = head;
			head = node;
			int len = getListLength(head->next);
			ListNode *h = head, *p, *q;

			for (int i = 1; i < len; i++) {
				p = getIthNodePrior(head, i);
				insertNode(head, p);
			}
			head = head->next;
			delete node;
			return head;
		}
		int getListLength(ListNode* head) {
			int len = 0;
			while (head) {
				len++;
				head = head->next;
			}
			return len;
		}
		ListNode *getIthNodePrior(ListNode *head, int n) {
			if (!head) return 0;

			while (head && n) {
				head = head->next;
				n--;
			}
			return head;
		}
		void insertNode(ListNode* head, ListNode* prior) {
			ListNode* node = prior->next, *it = head;
			while (it != prior) {
				if (node->val < it->next->val) {
					prior->next = node->next;
					node->next = it->next;
					it->next = node;
					break; }
				it = it->next;
			}
		}
		void print(ListNode* head) {
			//head = head->next;
			while (head) {
				cout << head->val << '\t';
				head = head->next;
			}
			cout << endl;
		}
		void clear(ListNode* head) {
			ListNode *p;
			while (head) {
				p = head;
				head = head->next;
				delete p;
			}
		}
		void test() {
			ListNode *head = new ListNode(3);
			head->next = new ListNode(2);
			head->next->next = new ListNode(1);
			head->next->next->next = new ListNode(9);
			head->next->next->next->next = new ListNode(8);
			head = insertionSortList(head);
			print(head);
			clear(head);
		}
};
int main() {
	Solution s;
	s.test();
}
