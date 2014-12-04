/*************************************************************************
  > File Name: binary_tree_level_order_traversal.cpp
  > Author: lax
  > Mail: xingkungao@gmail.com
  > Created Time: Wed 03 Dec 2014 08:40:28 PM CST
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <queue>
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
		vector<vector<int> > levelOrder(TreeNode *root) {
			vector<vector<int> > v;
			if (!root)
				return v;
			queue<TreeNode*> q1;
			queue<TreeNode*> q2;
			TreeNode* p;
			q1.push(root);
			while (!q1.empty() || !q2.empty()) {
				vector<int> level;
				if (!q1.empty()) {
					while (!q1.empty()) {
						p = q1.front();
						level.push_back(p->val);
						q1.pop();
						if (p->left) q2.push(p->left);
						if (p->right) q2.push(p->right);
					}
				}
				else {
					while (!q2.empty()) {
						p = q2.front();
						level.push_back(p->val);
						q2.pop();
						if (p->left) q1.push(p->left);
						if (p->right) q1.push(p->right);
					}
				}
				v.push_back(level);
			}
			return v;
		}
		void print(vector<vector<int> > v) {
			for (vector<vector<int> >::iterator i = v.begin(); i != v.end(); ++i) {
				for (vector<int>::iterator j = (*i).begin(); j != (*i).end(); ++j) 
					cout << *j << ' ';
				cout << endl;
			}
		}
		void test() {
			TreeNode *root = new TreeNode(3);
			root->left = new TreeNode(9);
			root->right = new TreeNode(20);
			root->right->left = new TreeNode(15);
			root->right->right = new TreeNode(7);
			print(levelOrder(root));
		}
};

int main() {
	Solution s;
	s.test();
}

