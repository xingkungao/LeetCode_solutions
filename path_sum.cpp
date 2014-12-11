/*************************************************************************
  > File Name: path_sum.cpp
  > Author: lax
  > Mail: xingkungao@gmail.com
  > Created Time: Thu 11 Dec 2014 03:53:48 PM CST
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
		bool hasPathSum(TreeNode *root, int sum) {
			return hasPathSumRecursive(root, sum);
		}
		bool hasPathSumRecursive(TreeNode *root, int sum) {
			if (!root)
				return false;
			if (!root->left && !root->right)
				return sum == root->val;
			if (root->left && root->right)
				return hasPathSumRecursive(root->left, sum - root->val) || hasPathSumRecursive(root->right, sum - root->val);
			if (root->left)
				return hasPathSumRecursive(root->left, sum - root->val); 
			if (root->right)
				return hasPathSumRecursive(root->right, sum - root->val); 
		}
		void test() {
			TreeNode *root = new TreeNode(5);

			root->left = new TreeNode(4);
			root->left->left = new TreeNode(11);
			root->left->left->left = new TreeNode(7);
			root->left->left->right = new TreeNode(2);

			root->right= new TreeNode(8);
			root->right->left = new TreeNode(13);
			root->right->right = new TreeNode(4);
			root->right->right->right = new TreeNode(1);
			cout << boolalpha << hasPathSum(root, 13) << endl;
		}
};
int main() {
	Solution s;
	s.test();
}
