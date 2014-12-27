/*************************************************************************
  > File Name: merge_k_sorted_lists.cpp
  > Author: lax
  > Mail: xingkungao@gmail.com
  > Created Time: Sat 27 Dec 2014 05:59:54 PM CST
 ************************************************************************/

#include "CPP.h"
#include "utility.h"
using namespace std;

class Solution {
	public:
		ListNode *mergeKLists(vector<ListNode *> &lists) {
			vector<ListNode*> heap;
			for (int i = 0; i < lists.size(); i++) 
				if (lists[i])
					heap.push_back(lists[i]);
			if (heap.empty())
				return 0;
			make_heap(heap.begin(), heap.end(), compare);
			ListNode *head = NULL, *tail, *p;
			while (!heap.empty()) {
				p = heap.front();
				pop_heap(heap.begin(), heap.end(), compare);
				heap.pop_back();
				if (p) {
					if (!head) { 
						head = tail = p;
					}
					else {
						tail->next = p;
						tail = tail->next;
					}
					if (p->next) {
						heap.push_back(p->next);
						push_heap(heap.begin(), heap.end(), compare);
					}
				}
			}
			if (tail) tail->next = 0;
			return head;
		}
		static bool compare(ListNode *p, ListNode *q) {
			if (!p)
				return false;
			if (!q)
				return true;
			return p->val > q->val;
		}

		void test() {
			vector<ListNode*> array;
			ListNode *h1 = new ListNode(5);
			h1->next = new ListNode(7);
			h1->next->next = new ListNode(9);
			array.push_back(h1);

			array.push_back(0);
			array.push_back(0);
			array.push_back(0);
			array.push_back(0);
			ListNode *h2 = new ListNode(1);
			h2->next = new ListNode(5);
			h2->next->next = new ListNode(6);
			array.push_back(h2);

			ListNode *h3 = new ListNode(2);
			h3->next = new ListNode(3);
			h3->next->next = new ListNode(4);
			array.push_back(h3);

			array.push_back(0);
			array.push_back(0);
			array.push_back(0);
			array.push_back(0);
			
			printSinglyLinkedList(mergeKLists(array));

		}
};


int main() {
	Solution s;
	s.test();
}
