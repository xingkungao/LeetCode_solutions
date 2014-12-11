/*************************************************************************
  > File Name: minimum_depth_of_binary_tree.cpp
  > Author: lax
  > Mail: xingkungao@gmail.com
  > Created Time: Thu 11 Dec 2014 02:53:20 PM CST
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <queue>
#include <climits>
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
		int minDepth(TreeNode *root) {
			if (!root)
				return 0;
			if (root->left && root->right)
				return std::min(minDepth(root->left), minDepth(root->right)) + 1;
			if (!root->left && !root->right)
				return 1;
			if (root->left)
				return minDepth(root->left) + 1;
			if (root->right)
				return minDepth(root->right) + 1;
		}
		int minDepthBFS(TreeNode *root) {
			if (!root)
				return 0;
			queue<TreeNode*> q[2];
			int level = 0;
			q[0].push(root);
			TreeNode *p;
			while (!q[0].empty() || !q[1].empty()) {
				int used = level & 1;
				while (!q[used].empty()) {
					p = q[used].front();
					q[used].pop();
					if (p->left)
						q[1-used].push(p->left);
					if (p->right)
						q[1-used].push(p->right);
					if (!p->left && !p->right)
						return level + 1;
				}
				level++;
			}
		}
		void test() {
			TreeNode *root = new TreeNode(1);
			root->left = new TreeNode(2);
			root->left->left = new TreeNode(2);
			root->right = new TreeNode(3);
			root->right->left = new TreeNode(3);
			cout << minDepth(root) << endl;
			cout << minDepthBFS(root) << endl;
			cout << endl;
		}
};
int main() {
	Solution s;
	s.test();
}
