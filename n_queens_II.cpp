/*************************************************************************
  > File Name: n_queens_II.cpp
  > Author: lax
  > Mail: xingkungao@gmail.com
  > Created Time: Wed 10 Dec 2014 09:38:24 PM CST
 ************************************************************************/

#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <cstring>
#include <cassert>
using namespace std;
class Solution { public:
	int totalNQueens(int n) {
		int *p = new int[n];
		int *a = new int[n];
		int *b = new int[2 * n];
		int *c = new int[2 * n];
		memset(a, 0, sizeof(int) * n);
		memset(b, 0, sizeof(int) * 2 * n);
		memset(c, 0, sizeof(int) * 2 * n);
		int cnt = 0;
		solveNQueensRecursive(n, a, b, c, 0, cnt); 
		return cnt;
	}
	void solveNQueensRecursive(int n, int *a, int *b, int *c, int l, int &cnt) {
		if (l == n && n) {
			cnt++;
			return;
		}
		for (int i = 0; i < n; i++) {
			if (!a[i] && !b[l + i] && !c[(n + i - l)]) {

				a[i] = b[l+i] = c[(n+i-l)] = 1;
				
				solveNQueensRecursive(n, a, b, c, l+1, cnt);

				a[i] = b[l+i] = c[(n+i-l)] = 0;
			}
		}

	}
	void test() {
		int n; 
		while (1)
		{
			cin >> n;
			cout << totalNQueens(n) << endl;
		}
	}
};


int main() {
	Solution s;
	s.test();
}
