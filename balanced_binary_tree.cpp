/*************************************************************************
  > File Name: balanced_binary_tree.cpp
  > Author: lax
  > Mail: xingkungao@gmail.com
  > Created Time: Thu 11 Dec 2014 02:28:30 PM CST
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

/**
 *
 *  * Definition for binary tree
 */
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
	public:
		bool isBalanced(TreeNode *root) {
			int h;
			return isBalanced(root, h);
		}
		bool isBalanced(TreeNode *root, int &h) {
			if (!root) {
				h = 0;
				return true;
			}
			int hl, hr;
			if (isBalanced(root->left, hl) && isBalanced(root->right, hr)) {
				h = std::max(hl, hr) + 1;
				return abs(hl - hr) <= 1;
			}
			return false;
		}
		void test() {
			TreeNode *root = new TreeNode(1);
			root->left = new TreeNode(2);
			root->right = new TreeNode(3);
			root->right->left = new TreeNode(6);
//			root->left->right = new TreeNode(8);
			root->left->left = new TreeNode(4);
			root->left->left->left = new TreeNode(5);
			cout << boolalpha << isBalanced(root) << endl;
		}
};
int main() {
	Solution s;
	s.test();
}
