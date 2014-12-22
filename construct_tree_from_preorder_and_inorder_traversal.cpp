/*************************************************************************
    > File Name: construct_tree_from_preorder_and_inorder_traversal.cpp
    > Author: lax
    > Mail: xingkungao@gmail.com
    > Created Time: Sun 21 Dec 2014 09:19:28 PM CST
 ************************************************************************/

#include "CPP.h"
#include "utility.h"
using namespace std;
class Solution {
	public:
		TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
			int len = preorder.size();
			if (!len || len != inorder.size())
				return 0;
			return buildTreeRecursive(preorder, 0 , len -1 , inorder, 0, len - 1);

		}
		TreeNode *buildTreeRecursive(vector<int> &preorder, int lpre, int rpre, vector<int> &inorder, int lin, int rin) {
			if (lpre > rpre && lin > rin)
				return 0;
			int data = preorder[lpre];
			TreeNode *root = new TreeNode(data);
			for (int i = lin; i <= rin; ++i) {
				if (inorder[i] == data)  {
					root->left = buildTreeRecursive(preorder, lpre + 1, lpre + i - lin , inorder, lin, i - 1);
					root->right = buildTreeRecursive(preorder, rpre + 1 + i - rin  , rpre , inorder, i+1, rin);
					break;
				}
			}
			return root;
		}
		TreeNode *buildTreeIterative(vector<int> &preorder, vector<int> &inorder) {
			stack<TreeNode*> stk;
			return 0;
		}
		void test() {
			vector<int> v1, v2;
			int len, x;
			cin >> len;
			for (int i = 0; i < len; i++) {
				cin >> x;
				v1.push_back(x);
			}
			for (int i = 0; i < len; i++) {
				cin >> x;
				v2.push_back(x);
			}
			printBinaryTree(buildTree(v1, v2));
		}
};

int main() {
	Solution s;
	s.test();
}
