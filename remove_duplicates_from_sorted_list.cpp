/*************************************************************************
  > File Name: remove_duplicates_from_sorted_list.cpp
  > Author: lax
  > Mail: xingkungao@gmail.com
  > Created Time: Fri 12 Dec 2014 03:34:52 PM CST
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
		ListNode *deleteDuplicates(ListNode *head) {
			ListNode *p = head, *q;
			while (p) {
				if(p->next && p->next->val == p->val) {
					q = p->next;
					p->next = p->next->next;
					delete q;
				}
				else 
					p = p->next;
			}
			return head;
		}
		ListNode* create() {
			int x;
			ListNode *head = 0, *tail;
			while (cin >> x && x > 0) {
				if (!head) {
					head = tail = new ListNode(x);
				}
				else {
					tail->next = new ListNode(x);
					tail = tail->next;
				}
			}
			return head;
		}
		/* notice here a double pointer is necessary, in order to assign the original argument head to null */
		void clear(ListNode **head) {
			ListNode *p;
			while (*head) {
				p = *head;
				*head = (*head)->next;
				delete p;
			}
			*head = 0;
		}
		void print(ListNode *head) {
			while (head) {
				cout << head->val << " ";
				head = head->next;
			}
			cout << endl;
		}
		void test() {
			ListNode *head;
			while (1) {
				head = create();
				cout << "original\n";
				print(head);
				head = deleteDuplicates(head); cout << "deleted\n";
				print(head);
				print(head);
				clear(&head);
				cout << "cleared\n";
				assert(!head);
				print(head);
			}
		}
};
int main() {
	Solution s;
	s.test();
}

