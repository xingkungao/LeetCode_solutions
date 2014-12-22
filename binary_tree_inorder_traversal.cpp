/*************************************************************************
  > File Name: binary_tree_inorder_traversal.cpp
  > Author: lax
  > Mail: xingkungao@gmail.com
  > Created Time: Mon 22 Dec 2014 05:08:12 PM CST
 ************************************************************************/

#include "CPP.h"
#include "utility.h"
using namespace std;

class Solution {
	public:
		vector<int> inorderTraversal(TreeNode *root) {
			vector<int> ret;
			stack<TreeNode*> stk;
			TreeNode *node = root;
			do {
				while (node) {
					stk.push(node);
					node = node->left;
				}
				if (!stk.empty()) {
					node = stk.top();
					stk.pop();
					ret.push_back(node->val);
					node = node->right;
				}
			}while (!stk.empty() || node);
			return ret;
		}
		vector<int> MorrisInorderTraversal(TreeNode *root) {
			// threaded binary tree
			vector<int> ret;
			if (!root)
				return ret;
			TreeNode *current = root, *p;
			while (current) {
				if(current->left) {
					p = current->left;
					while (p->right && p->right != current)
						p = p->right;
					if (p->right == NULL) {
						p->right = current;
						current = current->left;
					}
					else {
						p->right = 0;
						ret.push_back(current->val);
						current = current->right;
					}
				}
				else {
					ret.push_back(current->val);
					current = current->right;
				}
			}
			return ret;
		}
		void test() {
			TreeNode *root = new TreeNode(1);
			root->right = new TreeNode(2);
			root->right->left = new TreeNode(3);
			print1DVector(inorderTraversal(root));
			print1DVector(MorrisInorderTraversal(root));
			print1DVector(inorderTraversal(root));
		}
};


int main() {
	Solution s;
	s.test();
}
