/*************************************************************************
  > File Name: binary_tree_preorder_traversal.cpp
  > Author: lax
  > Mail: xingkungao@gmail.com
  > Created Time: Tue 02 Dec 2014 11:43:38 PM CST
 ************************************************************************/

#include "CPP.h"
#include "utility.h"
using namespace std; 

class Solution {
	public:
		vector<int> preorderTraversal(TreeNode *root) {
			//			return preorderTraversalRecurisve(root);
			//			return preorderTraversalIterative(root);
			return preorderTraversalMorris(root);
		}

		vector<int> preorderTraversalRecursive(TreeNode *root) {
			vector<int> v;
			preorderTraverse(root, v);
			return v;
		}
		void preorderTraverse(TreeNode *root, vector<int> &v) {
			if (!root) return;
			v.push_back(root->val);
			preorderTraverse(root->left, v);
			preorderTraverse(root->right, v);
		}


		vector<int> preorderTraversalIterative(TreeNode *root) {
			vector<int> v;
			if (!root) 
				return v;
			stack<TreeNode*> s;
			TreeNode *p;
			s.push(root);
			while (!s.empty()) {
				p = s.top();
				v.push_back(p->val);
				s.pop();
				if (p->right) s.push(p->right);
				if (p->left) s.push(p->left);
			}
			return v;
		}


		vector<int> preorderTraversalMorris(TreeNode *root) {
			vector<int> ret;
			TreeNode *cur = root, *pre;

			while (cur != NULL) {
				if (cur->left == NULL) {
					ret.push_back(cur->val);
					cur = cur->right;
				}
				else {
					pre = cur->left;
					while (pre->right != NULL && pre->right != cur)
						pre = pre->right;
					if (pre->right == NULL) {
						ret.push_back(cur->val);
						pre->right = cur;
						cur = cur->left;
					}
					else {
						pre->right = NULL;
						cur = cur->right;
					}
				}
			}
			return ret;

		}

		void test() {
			TreeNode* root = new TreeNode(1);
			root->left = new TreeNode(2);
			root->right = new TreeNode(3);
			root->left->left = new TreeNode(4);
			root->left->right = new TreeNode(5);
			root->right->left = new TreeNode(6);
			root->right->right = new TreeNode(7);
			vector<int> v = preorderTraversalRecursive(root);
			vector<int> v1 = preorderTraversalIterative(root);
			vector<int> v2 = preorderTraversalMorris(root);
			cout << "recurisive vs iterative, same result? " << boolalpha << std::equal(v.begin(), v.end(), v1.begin()) << endl; 
			cout << "recurisive vs morris, same result? " << boolalpha << std::equal(v.begin(), v.end(), v2.begin()) << endl; 
		}

};

int main() {
	Solution s;
	s.test();
}
