/*************************************************************************
    > File Name: binary_tree_maximum_path_num.cpp
    > Author: lax
    > Mail: xingkungao@gmail.com
    > Created Time: Sun 14 Dec 2014 07:09:23 PM CST
 ************************************************************************/

#include "CPP.h"
#include "utility.h"
using namespace std;
class Solution {
	public:
		int maxPathSum(TreeNode *root) {
			if (!root)
				return 0;
			int m = INT_MIN;
			maxPathSumRecursive(root, m);
			return m;
		}
		int maxPathSumRecursive(TreeNode *root, int &m) {
			if (!root) {
				return 0;
			}
			int a, b, val = root->val;
			a = maxPathSumRecursive(root->left, m);
			b = maxPathSumRecursive(root->right, m);
			int ret = max(val, max(val + a, val + b));
			m = max(m, max(ret, val + a + b));
			/*
cout << "node: " << val << endl;
cout << "ret:" << ret << " m:" << m << endl;
*/
			return ret;
		}
		void test() {
			TreeNode *root = new TreeNode(1);
			root->left = new TreeNode(-3);
			root->right = new TreeNode(-2);
			root->left->left = new TreeNode(8);
			root->left->right = new TreeNode(-9);
			cout << maxPathSum(root) << endl;
		}
};

int main() {
	Solution s;
	s.test();
}

