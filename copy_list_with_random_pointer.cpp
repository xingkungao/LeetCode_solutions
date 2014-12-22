/*************************************************************************
  > File Name: copy_list_with_random_pointer.cpp
  > Author: lax
  > Mail: xingkungao@gmail.com
  > Created Time: Mon 22 Dec 2014 09:45:01 AM CST
 ************************************************************************/

#include "CPP.h"
#include "utility.h"

/**
 *
 *  * Definition for singly-linked list with a random pointer.
 */
struct RandomListNode {
	int label;
	RandomListNode *next, *random;
	RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
	public:
		RandomListNode *copyRandomList(RandomListNode *head) {
			if (!head)
				return 0;
			RandomListNode *p = head, *dup, *q;
			while (p) {
				q = new RandomListNode(p->label);
				q->next = p->next;
				p->next = q;
				p = q->next;
			}
			dup = head->next;
			p = head;

			while (p) {
				p->next->random = 0;
				if (p->random)
					p->next->random = p->random->next;
				p = p->next->next;
			}

			p = head;
			q = dup;
			while (p) {
				p->next = q->next;
				q->next = 0;
				if (p->next) q->next = p->next->next;
				p = p->next;
				q = q->next;
			}
//			printRandomList(dup);
			return dup;
		}
		void printRandomList(RandomListNode *head) {
			while (head) {
				cout << head->label<< '\t' << head->next  << '\t' << head->random << endl;
				head = head ->next;
			}
		}
		void test() {
			RandomListNode *p1= new RandomListNode(1);
			RandomListNode *p2= new RandomListNode(2);
			RandomListNode *p3= new RandomListNode(3);
			RandomListNode *p4= new RandomListNode(4);
			RandomListNode *p5= new RandomListNode(5);

			p1->next = p2;
			p2->next = p3;
			p3->next = p4;
			p4->next = p5;

			p1->random = p3;
			p2->random = p1;
//			p3->random = p5;
			p4->random = p3;
			p5->random = p2;
			printRandomList(copyRandomList(p1));
		}
};
int main() {
	Solution s;
	s.test();
}
