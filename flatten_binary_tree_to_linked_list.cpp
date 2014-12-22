/*************************************************************************
  > File Name: flatten_binary_tree_to_linked_list.cpp
  > Author: lax
  > Mail: xingkungao@gmail.com
  > Created Time: Sun 21 Dec 2014 10:06:49 PM CST
 ************************************************************************/

#include "CPP.h"
#include "utility.h"
using namespace std;

class Solution {
	public:
		void flatten(TreeNode *root) {
			if (!root)
				return;
			TreeNode *head, *tail;
			//			flattenRecursive(root, &root, &tail); // recurisve
			flattenIterative(root); // iterative
		}
		void flattenRecursive(TreeNode *root, TreeNode **head, TreeNode **tail) {
			if (!root) {
				*head = *tail = 0;
				return;
			}
			TreeNode *hl, *tl, *hr, *tr;
			flattenRecursive(root->left, &hl, &tl);
			flattenRecursive(root->right, &hr, &tr);
			root->right = hr;
			root->left = 0;
			if (hl) {
				tl->right= root->right;
				root->right = hl;
			}
			*head = root;
			*tail = tr ? tr : (tl ? tl : *head);
		}
		void flattenIterative(TreeNode *root) {
			TreeNode *current = root, *p;
			while (current) {
				if (current->left) {
					p = current->left;
					while (p->right) 
						p = p->right;
					p->right = current->right;
					current->right = current->left;
					current->left = 0;
				}
				current = current->right;
			}

		}
		void test() {
			TreeNode *root = new TreeNode(1);
			root->left = new TreeNode(2);
			root->left->left = new TreeNode(3);
			root->left->right = new TreeNode(4);
			root->right = new TreeNode(5);
			root->right->right = new TreeNode(6);
			flatten(root);
			printBinaryTree(root);
		}
};

int main( ){
	Solution s;
	s.test();
}

