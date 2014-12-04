/*************************************************************************
  > File Name: symmetric_tree.cpp
  > Author: lax
  > Mail: xingkungao@gmail.com
  > Created Time: Tue 02 Dec 2014 09:00:50 PM CST
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
/**
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
		bool isSymmetric(TreeNode *root) {
			if (!root) return true;
			if (!root->left && !root->right) return true;
			return  root->left && root->right && isSymmetric(root->left, root->right);
		}
		bool isSymmetric(TreeNode *p, TreeNode *q) {
			if (!q && !p) return true;
			return p && q && p->val == q->val && isSymmetric(p->left, q->right) && isSymmetric(p->right, q->left);
		}
};
int main() {
}
