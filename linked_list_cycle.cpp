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
		bool hasCycle(ListNode *head) {
			if (!head || !head->next)
				return false;
			ListNode *p = head, *q = head->next;
			do {
				p = p->next;
				q = q->next->next;
				if (p == q)
					return true;
			}while (p && q && q->next);
			return false;
		}
};
int main() {
}

