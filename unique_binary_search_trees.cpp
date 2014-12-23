/*************************************************************************
    > File Name: unique_binary_search_trees.cpp
    > Author: lax
    > Mail: xingkungao@gmail.com
    > Created Time: Tue 23 Dec 2014 05:41:45 PM CST
 ************************************************************************/

#include "CPP.h"
#include "utility.h"
using namespace std;

class Solution  {
	public:
		int numTrees(int n) {
			if (!n)
				return n;
			int catalan = 1;
			for (int i = 0; i < n; i++) {
				catalan =  catalan * 2 * (2 * i + 1) / (i + 2);
			}
			return catalan;
		}
		void test() {
			int x;
			while (1) {
				cin >> x;
				cout << numTrees(x) << endl;
			}
		}
};

int main() {
	Solution s;
	s.test();
}
