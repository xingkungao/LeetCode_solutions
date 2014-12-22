/*************************************************************************
  > File Name: construct_tree_from_inorder_and_postorder_traversal.cpp
  > Author: lax
  > Mail: xingkungao@gmail.com
  > Created Time: Sun 21 Dec 2014 08:15:50 PM CST
 ************************************************************************/

#include "CPP.h"
#include "utility.h"
using namespace std;


class Solution {
	public:
		TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
			int len = postorder.size();
			if (!len || len != inorder.size())
				return 0;
			return buildTreeRecursive(inorder,0, len-1, postorder, 0, len-1);
		}
		TreeNode *buildTreeRecursive(vector<int> &inorder, int l1, int r1, vector<int> &postorder, int l2, int r2) {
//			cout << "(" << l1 << "," <<  r1 << ") (" << l2  << "," << r2 << ")" <<  endl;
			if (l1 > r1 && l2 > r2)
				return 0;
			int data = postorder[r2];
			TreeNode *root = new TreeNode(data);
			if (r1 == l1 && l2 == r2)
				return root;
			for (int i = l1; i <= r1; ++i) {
				if (inorder[i] == data) {
					root->left = buildTreeRecursive(inorder,l1, i - 1, postorder, l2, l2 + i - 1 - l1);
					root->right = buildTreeRecursive(inorder,i + 1, r1, postorder, r2 + i - r1, r2 - 1);
					break;
				}
			}
			return root;
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
