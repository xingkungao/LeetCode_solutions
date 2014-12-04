/*************************************************************************
  > File Name: linked_list_cycle.cpp
  > Author: lax
  > Mail: xingkungao@gmail.com
  > Created Time: Wed 03 Dec 2014 01:35:53 PM CST
 ************************************************************************/

#include <iostream>
#include <cstdio>
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
		ListNode *detectCycle(ListNode *head) {
			if (!head || !head->next)
				return 0;
			ListNode *p = head, *q = head;
			do {
				p = p->next;
				q = q->next->next;
				if (p == q) {
					// has cycle
					q = head;
					while (q != p) {
						p = p->next;
						q = q->next;
					}
					return p;
				}
			}while (p && q && q->next);
			return 0;
		}
};
int main() {
}

