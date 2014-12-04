/*************************************************************************
  > File Name: binary_tree_preorder_traversal.cpp
  > Author: lax
  > Mail: xingkungao@gmail.com
  > Created Time: Tue 02 Dec 2014 11:43:38 PM CST
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cassert>
#include <vector>
#include <stack>
using namespace std; /**
					  *  * Definition for singly-linked list.
					  */
struct TreeNode{
	int val;
	TreeNode *left, *right;
	TreeNode(int x) : val(x), left(NULL),right(NULL) {}
};

/* recursive approach 
   class Solution {
   public:
   vector<int> preorderTraversal(TreeNode *root) {
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
   };

*/
/* iterative appraoch */
class Solution {
	public:
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

		vector<int> preorderTraversal(TreeNode *root) {
			vector<int> v;
			if (!root) 
				return v;
			stack<TreeNode*> s;
			TreeNode *p;
			s.push(root);
			while (!s.empty()) {
				p = s.top();
				v.push_back(p->val);
				//printVector(v);
				s.pop();
				if (p->right) s.push(p->right);
				if (p->left) s.push(p->left);
			}
			return v;
		}
		void printVector(vector<int> &v) {
			for (vector<int>::iterator it = v.begin(); it != v.end(); ++it)
				cout << "  " << *it;
			cout << endl;
		}

};

int main() {
	Solution s;
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->left->left = new TreeNode(4);
	root->left->right = new TreeNode(5);
	root->right->left = new TreeNode(6);
	root->right->right = new TreeNode(7);
	vector<int> v = s.preorderTraversalRecursive(root);
	vector<int> v1 = s.preorderTraversal(root);
	cout << std::equal(v.begin(), v.end(), v1.begin()) << endl; 
	s.printVector(v);
	s.printVector(v1);

}
