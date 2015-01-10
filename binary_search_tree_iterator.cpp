/*************************************************************************
  > File Name: binary_search_tree_iterator.cpp
  > Author: lax
  > Mail: xingkungao@gmail.com
  > Created Time: Sat 10 Jan 2015 04:22:40 PM CST
 ************************************************************************/

#include "CPP.h"
#include "utility.h"
using namespace std;

class BSTIterator {
	private:
		stack<TreeNode*> stk;
	public:
		BSTIterator(TreeNode *root) {
			while (root) {
				stk.push(root);
				root = root->left;
			}
		}

		/** @return whether we have a next smallest number */
		bool hasNext() {
			return !stk.empty();
		}

		/** @return the next smallest number */
		int next() {
			if (hasNext()) {
				TreeNode *p = stk.top(), *q;
				stk.pop();
				q = p->right;
				while (q) {
					stk.push(q);
					q = q->left;
				}
				return p->val;
			}
		}

		void test() {
			while (hasNext()) {
				cout << next() << endl;
			}
		}
};
int main() {
			TreeNode *root = new TreeNode(5);
			/*
			root->left = new TreeNode(3);
			root->right = new TreeNode(7);
			root->left->left = new TreeNode(1);
			root->left->right = new TreeNode(4);
			root->right->left = new TreeNode(6);
			root->right->right = new TreeNode(8);
			*/

	BSTIterator s(root);
	s.test();
}




/**
 *
 * * Your BSTIterator will be called like this:
 *
 * * BSTIterator i = BSTIterator(root);
 *
 * * while (i.hasNext()) cout << i.next();
 *
 * */
