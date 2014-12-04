/*************************************************************************
  > File Name: maximum_depth_of_binary_tree.cpp
  > Author: lax
  > Mail: xingkungao@gmail.com
  > Created Time: Wed 03 Dec 2014 09:10:09 PM CST
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <algorithm>
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
		int maxDepth(TreeNode *root) {
			if (!root) 
				return 0;
			return 1 + std::max(maxDepth(root->left), maxDepth(root->right));
		}
};
int main() {
}

