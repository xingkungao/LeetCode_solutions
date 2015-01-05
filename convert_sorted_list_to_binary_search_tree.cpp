/*************************************************************************
    > File Name: convert_sorted_list_to_binary_search_tree.cpp
    > Author: lax
    > Mail: xingkungao@gmail.com
    > Created Time: Mon 05 Jan 2015 02:58:15 PM CST
 ************************************************************************/

#include "CPP.h"
#include "utility.h"
using namespace std;

class Solution {
	public:
		TreeNode *sortedListToBST(ListNode *head) {
//			return sortedListToBSTRecursive(head);
			return sortedListToBSTRecursiveStandard(head);
		}

		/* recurisve top-down approach: nlog(n)
		 */
		TreeNode *sortedListToBSTRecursive(ListNode *head) {
			if (!head)
				return 0;
			TreeNode *root;
			ListNode *mid;
			mid = getMiddle(head);
			
			if (mid) {
				root = new TreeNode(mid->val);
				if (mid != head) root->left = sortedListToBSTRecursive(head);
				root->right = sortedListToBSTRecursive(mid->next);
			}
			return root;
		}
		ListNode *getMiddle(ListNode *head) {
			if (!head) 
				return 0;
			ListNode *p = head, *q = head, *pre = 0;
			while (q && q->next) {
				pre = p;
				p = p->next;
				q = q->next->next;
			}
			if (pre) pre->next = 0;
			return p;
		}

		/* recurisve top-down approach: nlog(n)
		 */
		TreeNode *sortedListToBSTRecursiveStandard(ListNode *head) {
			int len = getLength(head);
			if (len == 0)
				return NULL;
			return sortedListToBSTBottomUp(head, 0, len - 1);
		}

		TreeNode *sortedListToBSTBottomUp(ListNode *&head, int left, int right) {
			if (left > right)
				return 0;
			int mid = left + (right - left) / 2;
			TreeNode *root = new TreeNode(0);
			root->left = sortedListToBSTBottomUp(head, left, mid - 1);
			root->val = head->val;
			head = head->next;
			root->right = sortedListToBSTBottomUp(head, mid + 1, right);
			return root;
		}
		int getLength(ListNode *head) {
			int len = 0;
			while (head) {
				len++;
				head = head->next;
			}
			return len;
		}

		void test() {
			ListNode *head;
			TreeNode *root;
			vector<int> v;
			while (1) {
				head = createSinglyLinkedList();
				root = sortedListToBST(head);
				v = serializeBinaryTree(root);
				print1DVector(v);
			}
		}
};

int main() {
	Solution s;
	s.test();
}
