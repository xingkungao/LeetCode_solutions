/*************************************************************************
  > File Name: validate_binary_tree.cpp
  > Author: lax
  > Mail: xingkungao@gmail.com
  > Created Time: Thu 11 Dec 2014 01:09:41 PM CST
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <climits>
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
		bool isValidBST(TreeNode *root) {
			long long floor = INT_MIN;
			floor --;
			long long ceiling = INT_MAX;
			ceiling++;
			return isValidBSTRecursive(root, floor, ceiling);
		}
		bool isValidBSTRecursive(TreeNode *root, long long mi, long long ma) {
			if (!root)
				return true;
			return root->val > mi && root->val < ma && (!root->left || isValidBSTRecursive(root->left, mi, root->val)) && (!root->right || isValidBSTRecursive(root->right, root->val, ma));

		}
		bool test() {
			TreeNode* root = new TreeNode(6);
			root->left = new TreeNode(3);
			root->right = new TreeNode(9);
			root->left->left = new TreeNode(1);
			//root->left->right = new TreeNode(8);
			//root->right->left = new TreeNode(2);
			root->right->right = new TreeNode(10);
			cout << boolalpha << isValidBST(root) << endl;
		}

};
int main() {
	Solution s;
	s.test();
}
