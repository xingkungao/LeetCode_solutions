/*************************************************************************
  > File Name: unique_binary_search_trees_II.cpp
  > Author: lax
  > Mail: xingkungao@gmail.com
  > Created Time: Tue 23 Dec 2014 07:21:46 PM CST
 ************************************************************************/

#include "CPP.h"
#include "utility.h"
using namespace std;

class Solution {
	public:
		vector<TreeNode *> generateTrees(int n) {
			return generateTreesRecursive(1, n);
		}
		vector<TreeNode*> generateTreesRecursive(int l, int r) {
			vector<TreeNode*> v;
			if (l > r) {
				v.push_back(0);
			}
			else {
				for (int i = l; i <= r; i++) {
					vector<TreeNode*> lv = generateTreesRecursive(l, i-1);
					vector<TreeNode*> rv = generateTreesRecursive(i + 1, r);
					for (int j = 0; j < lv.size(); j++) {
						for (int k = 0; k < rv.size(); k++) {
							TreeNode *root = new TreeNode(i);
							root->left = lv[j];
							root->right = rv[k];
							v.push_back(root);
						}
					}
				}
			}
			return v;
		}
		void test() {
			int n;
			vector<TreeNode*> v;
			TreeNode *p;
			while (1) {
				cin >> n;
				v = generateTrees(n);
				cout << "# of solution:" << v.size() << endl;
				for (int i = 0; i  < v.size(); i++)  {
					p = v[i];
					printBinaryTree(p);
					cout << endl << endl;
				}
			}
		}
};


int main() {
	Solution s;
	s.test();
}
