/*************************************************************************
  > File Name: binary_tree_zigzag_level_order_traversal.cpp
  > Author: lax
  > Mail: xingkungao@gmail.com
  > Created Time: Mon 22 Dec 2014 09:24:53 PM CST
 ************************************************************************/

#include "CPP.h"
#include "utility.h"
using namespace std;

class Solution {
	public:
		vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
			vector<vector<int> > ret;
			if (!root)
				return ret;
			stack<TreeNode*> q1;
			stack<TreeNode*> q2;
			TreeNode *node;
			int level = 0;
			q1.push(root);
			while (!q1.empty() || !q2.empty()) {
				vector<int> level;
				if (!q1.empty()) 
					while (!q1.empty()) {
						node = q1.top();
						q1.pop();
						level.push_back(node->val);
						if (node->left) q2.push(node->left);
						if (node->right) q2.push(node->right);
					}
				else if (!q2.empty()) 
					while (!q2.empty()) {
						node = q2.top();
						q2.pop();
						level.push_back(node->val);
						if (node->right) q1.push(node->right);
						if (node->left) q1.push(node->left);
					}
				ret.push_back(level);
			}
			return ret;
		}
		void test() {
			TreeNode *root = new TreeNode(1);
			root->left = new TreeNode(2);
			root->right = new TreeNode(3);
			root->left->left = new TreeNode(4);
			root->left->right = new TreeNode(5);
			root->right->left = new TreeNode(6);
			root->right->right = new TreeNode(7);
			print2DVector(zigzagLevelOrder(root));

		}
};


int main() {
	Solution s;
	s.test();
}
