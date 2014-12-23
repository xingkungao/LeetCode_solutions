/*************************************************************************
  > File Name: path_sum_II.cpp
  > Author: lax
  > Mail: xingkungao@gmail.com
  > Created Time: Tue 23 Dec 2014 05:07:37 PM CST
 ************************************************************************/

#include "CPP.h"
#include "utility.h"
using namespace std;

class Solution {
	public:
		vector<vector<int> > pathSum(TreeNode *root, int sum) {
			vector<vector<int> > ret;
			vector<int> v;
			pathSumRecursive(root, ret, sum, v);
			return ret;
		}
		void pathSumRecursive(TreeNode *root, vector<vector<int> > &ret, int sum, vector<int> &v) {
			if (!root)
				return;
			v.push_back(root->val);
			if (root->left || root->right)  {
				pathSumRecursive(root->left, ret, sum - root->val, v);
				pathSumRecursive(root->right, ret, sum - root->val, v);
			}
			else if (root->val == sum)  {
				ret.push_back(v);
			}
			v.pop_back();
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
			print2DVector(pathSum(root, 22)); 
		}

};


int main() {
	Solution s;
	s.test();
}
