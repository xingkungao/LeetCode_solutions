/*************************************************************************
  > File Name: populating_next_right_pointers_in_each_node_II.cpp
  > Author: lax
  > Mail: xingkungao@gmail.com
  > Created Time: Wed 24 Dec 2014 02:30:30 PM CST
 ************************************************************************/

#include "CPP.h"
#include "utility.h"
using namespace std;

/**
 *  * Definition for binary tree with next pointer.
 */
struct TreeLinkNode {
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
	public:
		void connect(TreeLinkNode *root) {
			if (!root)
				return;
			TreeLinkNode *pnode = root, *cnode = 0, *head = 0;

			while (pnode) {

				while (pnode) {
					if (pnode->left) {
						if (!cnode) {
							cnode = head = pnode->left;
						}
						else {
							cnode->next = pnode->left;
							cnode = cnode->next;
						}
					}

					if (pnode->right) {
						if (!cnode) {
							cnode = head = pnode->right;
						}
						else {
							cnode->next = pnode->right;
							cnode = cnode->next;
						}
					}
					pnode = pnode->next;
				}
				pnode = head;
				head = 0;
				cnode = 0;
			}
		}
		void test() {
			TreeLinkNode *root = new TreeLinkNode(1);
			/*
			root->left = new TreeLinkNode(2);
			root->left->left = new TreeLinkNode(4);
			root->left->right= new TreeLinkNode(5);
			*/

			root->right = new TreeLinkNode(3);
			//			root->right->left = new TreeLinkNode(6);
			root->right->right = new TreeLinkNode(7);
			connect(root);
			TreeLinkNode *node;
			node = root;
			while (root) {
				node = root;
				while (node) {
					cout << node->val << '\t';
					node = node->next;
				}
				cout << endl;
				root = root ->left ? root->left : root->right;
			}
			cout << endl;
		}

};

int main() {
	Solution s;
	s.test();
}
