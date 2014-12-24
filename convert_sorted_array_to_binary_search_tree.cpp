/*************************************************************************
  > File Name: convert_sorted_array_to_binary_search_tree.cpp
  > Author: lax
  > Mail: xingkungao@gmail.com
  > Created Time: Wed 24 Dec 2014 12:05:52 AM CST
 ************************************************************************/

#include "CPP.h"
#include "utility.h"
using namespace std;

class Solution {
	public:
		TreeNode *sortedArrayToBST(vector<int> &num) {
			return sortedArrayToBSTRecursive(num, 0, num.size() - 1);
		}
		TreeNode *sortedArrayToBSTRecursive(vector<int> &num, int l, int r) {
			if (l > r)
				return NULL;
			int mid = (l + r) / 2;
			TreeNode *root = new TreeNode(num[mid]);
			root->left = sortedArrayToBSTRecursive(num, l, mid - 1);
			root->right = sortedArrayToBSTRecursive(num, mid + 1, r);
			return root;
		}
		/*
		TreeNode *sortedArrayToBSTIterative(vector<int> &num) {
			return 0;
		}
		*/
		void test() {
			vector<int> v;
			int x;
			while (1) {
				while (cin >> x && x > 0) 
					v.push_back(x);
				print1DVector(serializeBinaryTree(sortedArrayToBST(v)));
				v.clear();
			}
		}
};

int main() {
	Solution s;
	s.test();
}
