/*************************************************************************
  > File Name: recover_binary_search_tree.cpp
  > Author: lax
  > Mail: xingkungao@gmail.com
  > Created Time: Sun 04 Jan 2015 08:53:58 PM CST
 ************************************************************************/

#include "CPP.h"
#include "utility.h"
using namespace std;

class Solution {
	public:
		void recoverTree(TreeNode *root) {
//			recoverTreeRrcursive(root);
			recoverTreeMorris(root);
		}
		void recoverTreeRrcursive(TreeNode *root) {
			TreeNode *first = 0, *second = 0, *pre = 0, *next = 0;
			recoverTreeRecursiveUtil(root, first, second, pre, next);
			//			cout << "first: " << first->val << ", second:" << second->val << endl;
			swap(first->val, second->val);
		}
		void recoverTreeRecursiveUtil(TreeNode *root, TreeNode *&first, TreeNode *&second, TreeNode *&pre, TreeNode *&next) {
			if (!root) 
				return;
			recoverTreeRecursiveUtil(root->left, first, second, pre, next);

			if (!pre)
				pre = root;
			else if (!next) 
				next = root;
			else {
				pre = next;
				next = root;
			}

			if (pre && next && pre->val > next->val)  {
				if (!first)
					first = pre;
				second = next;
			}

			recoverTreeRecursiveUtil(root->right, first, second, pre, next);
		}

		void recoverTreeMorris(TreeNode *root) {
			TreeNode *current, *pred, *pre = 0, *next = 0, *first = 0, *second = 0;
			current = root;
			while (current) {
				if (!current->left) {

					if (!pre)
						pre = current;
					else if (!next) 
						next = current;
					else {
						pre = next;
						next = current;
					}
					current = current->right;
				}
				else {
					pred = current->left;
					while (pred->right && pred->right != current) 
						pred = pred->right;
					if (!pred->right) {
						pred->right = current;
						current = current->left;
					}
					else {
						pred->right = 0;

						if (!next) 
							next = current;
						else {
							pre = next;
							next = current;
						}

						current = current->right;
					}
				}
				if (pre && next && pre->val > next->val)  {
					if (!first)
						first = pre;
					second = next;
				}
			}
			if (first && second)  {
//				cout << "first: " << first->val << ", second:" << second->val << endl;
				swap(first->val, second->val);
			}
		}

		void inorderTraverse(TreeNode *root) {
			if (!root)
				return ;
			inorderTraverse(root->left);
			cout << root->val << '\t';
			inorderTraverse(root->right);
		}


		void test() {
			TreeNode *root = new TreeNode(5);
			root->left = new TreeNode(2);
			root->left->left = new TreeNode(7);
			root->left->right = new TreeNode(3);
			root->right = new TreeNode(1);

			inorderTraverse(root);
			cout << endl;
			recoverTree(root);
			inorderTraverse(root);
			cout << endl;

		}
};

int main() {
	Solution s;
	s.test();
}
