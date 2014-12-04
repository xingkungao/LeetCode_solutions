/*************************************************************************
  > File Name: sort_list.cpp
  > Author: lax
  > Mail: xingkungao@gmail.com
  > Created Time: Tue 02 Dec 2014 04:13:09 PM CST
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
		ListNode *sortList(ListNode *head) {
			if (!head)  return 0;
			else if (!head->next) return head;
			ListNode* t = findMid(head);
			ListNode* h = t->next;
			t->next = 0;
			/*
			cout << "print a\n";
			print(head);
			cout << "print b\n";
			print(h);
			*/
			ListNode* a = sortList(head);
			ListNode* b = sortList(h);
			/*
			cout << "print sorted a\n";
			print(a);
			cout << "print sorted b\n";
			print(b);
			*/
			return mergeList(a, b);
		}

		ListNode* findMid(ListNode *head) {
			int length = 0;
			if (!head) 
				return head;

			ListNode*p = head;
			while (p) {
				length++;
				p = p->next;
			}
			//cout << "length is" << length << endl;
			p = head;
			for (int i = 1; i < length / 2; i++) 
				p = p->next;
			//cout << "print mid\n";
			//print(p);
			return p;
		}

		ListNode* mergeList(ListNode *pa, ListNode *pb) {
			ListNode *p = 0, *head = 0;
			/*cout << "in merge, print a " << endl;
			print(pa);
			cout << "in merge, print b " << endl;
			print(pb);
			*/

			if (!pa)
				return pb;
			else if (!pb)
				return pa;

			while (pa && pb) {
				if (pa->val <= pb->val) {
					if (!p)
						p = head = pa;
					else {
						p->next = pa;
						p = p->next;
					}
					pa = pa->next;
				}
				else {
					if (!p) p = head = pb; 
					else {
						p->next = pb;
					p = p->next;
					}
					pb = pb->next;
				}
			}
			if (pa)  {
				p->next = pa;
			}
			else  {
				p->next = pb;
			}

			/*
			cout << "in merge, print result" << endl;
			print(head);
			*/
			return head;
		}
		void print(ListNode* h) {
			while (h) {
				cout << h->val << endl;
				h = h->next;
			}
		}
};
int main() {
	Solution s;
	ListNode* head = new ListNode(3);
	head->next = new ListNode(2);
	head->next->next = new ListNode(1);
	ListNode* h = s.sortList(head);
	ListNode* p;
	while (h) {
		p = h;
		cout << p->val << endl;
		h = h->next;
		delete p;
	}
}
