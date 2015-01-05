/*************************************************************************
  > File Name: validate_binary_search_tree.cpp
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
//			return isValidBSTRecursive(root); 
//			return isValidBSTRecursiveStandard(root); 
			return isValidBSTMorris(root); 
		}

		/** recursive, bound checking 
		*/
		bool isValidBSTRecursive(TreeNode *root) {
			long long floor = INT_MIN;
			floor --;
			long long ceiling = INT_MAX;
			ceiling++;
			return isValidBSTRecursiveUtil(root, floor, ceiling);
		}
		bool isValidBSTRecursiveUtil(TreeNode *root, long long mi, long long ma) {
			if (!root)
				return true;
			return root->val > mi && root->val < ma && (!root->left || isValidBSTRecursiveUtil(root->left, mi, root->val)) && (!root->right || isValidBSTRecursiveUtil(root->right, root->val, ma));
		}

		/** recursive, comparison checking 
		*/
		bool isValidBSTRecursiveStandard(TreeNode *root) {
			TreeNode *prev = 0;
			return isValidBSTRecursiveStandardUtil(root, prev);
		}
		bool isValidBSTRecursiveStandardUtil(TreeNode *root, TreeNode *&prev) {
			if (!root)
				return true;
			if (!isValidBSTRecursiveStandardUtil(root->left, prev))
				return false;
			if (prev && prev->val >= root->val)
				return false;
			prev = root;
			return isValidBSTRecursiveStandardUtil(root->right, prev);
		}

		bool isValidBSTMorris(TreeNode *root) {
			long long prev = INT_MIN;
			prev--;
			bool flag = true;
			TreeNode *cur = root, *pre;
			while (cur) {
				if (!cur->left) {
					if (prev >= cur->val)
						flag = false;
					prev = cur->val;
					cur = cur->right;
				}
				else {
					pre = cur->left;
					while (pre->right && pre->right != cur) 
						pre = pre->right;
					if (!pre->right) {
						pre->right = cur;
						cur = cur->left;
					}
					else {
						if (prev >= cur->val)
							flag = false;
						prev = cur->val;
						pre->right = 0;
						cur = cur->right;
					}
				}
			}
			return flag;
		}

		void test() {
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
