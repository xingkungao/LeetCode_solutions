/*************************************************************************
  > File Name: same_tree.cpp
  > Author: lax
  > Mail: xingkungao@gmail.com
  > Created Time: Tue 02 Dec 2014 09:00:50 PM CST
 ************************************************************************/

#include <iostream>
#include <cstdio>
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
		bool isSameTree(TreeNode *p, TreeNode *q) {
			if (!p && !q) return true;
			else if (p && q) return p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
			return false;
		}
};
int main() {
}
