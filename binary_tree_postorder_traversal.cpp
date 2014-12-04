/*************************************************************************
  > File Name: binary_tree_postorder_traversal.cpp
  > Author: lax
  > Mail: xingkungao@gmail.com
  > Created Time: Tue 02 Dec 2014 11:43:38 PM CST
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cassert>
#include <algorithm>
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

class Solution {
	public:
		vector<int> postorderTraversalRecursive(TreeNode *root) {
			vector<int> v;
			postorderTraverse(root, v);
			return v;
		}

		void postorderTraverse(TreeNode *root, vector<int> &v) {
			if (!root) return;
			postorderTraverse(root->left, v);
			postorderTraverse(root->right, v);
			v.push_back(root->val);
		}

/* iterative appraoch 1*/
		vector<int> preorderTraverseReversed(TreeNode *root) {
			vector<int> v;
			if (!root) return v;
			stack<TreeNode*> s;
			TreeNode* node;
			s.push(root);
			while (!s.empty()) {
				node = s.top();
				v.push_back(node->val);
				s.pop();
				if (node->left) s.push(node->left);
				if (node->right) s.push(node->right);
			}
			return v;
		}
		vector<int> postorderTraversal1(TreeNode *root) {
			vector<int>  v = preorderTraverseReversed(root);
			std::reverse(v.begin(), v.end());
			return v;
		}

/* iterative appraoch 2*/
		vector<int> postorderTraversal2(TreeNode *root) {
			enum Tag {L, R};
			struct StackNode{
				TreeNode* node;
				Tag tag;
				StackNode(TreeNode *node = NULL) : node(node), tag(L) {}
			};

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
	vector<int> v = s.postorderTraversalRecursive(root);
	vector<int> v1 = s.postorderTraversal1(root);
	cout << std::equal(v.begin(), v.end(), v1.begin()) << endl; 
	s.printVector(v);
	s.printVector(v1);

}
