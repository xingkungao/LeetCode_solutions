/*************************************************************************
  > File Name: sum_root_to_leaf_numbers.cpp
  > Author: lax
  > Mail: xingkungao@gmail.com
  > Created Time: Sun 14 Dec 2014 03:37:32 PM CST
 ************************************************************************/

#include <iostream>
#include <cstdio>
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
		int sumNumbers(TreeNode *root) {
			if (!root)
				return 0;
			int sum = 0;
			sumNumbersRecursive(root, 0,  sum); 
			return sum;
		}

		void sumNumbersRecursive(TreeNode *root, int number, int &sum) {
			if (!root->left && !root->right) {
				sum = sum + number * 10 + root->val;
			}

			if (root->left) 
				sumNumbersRecursive(root->left, number * 10 + root->val,  sum); 

			if (root->right) 
				sumNumbersRecursive(root->right, number * 10 + root->val,  sum); 
		}

		void test() {
			TreeNode *root = new TreeNode(1);
			root->left = new TreeNode(2);
			root->right = new TreeNode(3);
			cout << sumNumbers(new TreeNode(5)) << endl;
		}
};
int main() {
	Solution s;
	s.test();
}

