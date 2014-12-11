/*************************************************************************
  > File Name: n_queens.cpp
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
	vector<vector<string> > solveNQueens(int n) {
		int *p = new int[n];
		int *a = new int[n];
		int *b = new int[2 * n];
		int *c = new int[2 * n];
		memset(a, 0, sizeof(int) * n);
		memset(b, 0, sizeof(int) * 2 * n);
		memset(c, 0, sizeof(int) * 2 * n);
		vector<vector<string> > v;
		vector<string> board;
		solveNQueensRecursive(v, board, n, a, b, c, 0); 
		return v;
	}
	void solveNQueensRecursive(vector<vector<string> > &v, vector<string> &board, int n, int *a, int *b, int *c, int l) {
		if (l == n && n) {
			v.push_back(board);
			return;
		}
		string line(n, '.');
		for (int i = 0; i < n; i++) {
			if (!a[i] && !b[l + i] && !c[(n + i - l)]) {
				line[i] = 'Q';
				board.push_back(line); a[i] = b[i+l] = c[(n+i-l)] = 1;

				solveNQueensRecursive(v, board, n, a, b, c, l+1);

				board.pop_back();
				line[i] = '.';
				a[i] = b[l+i] = c[(n+i-l)] = 0;
			}
		}

	}
	void print(vector<vector<string> > v) {
		for (int i = 0; i  < v.size(); i++)  {
			cout << endl << i + 1 << endl;
			for (int j = 0; j < v[i].size(); j++) 
				cout << v[i][j] << endl;
		}
	}
	void print(vector<string> v) {
		for (int i = 0; i  < v.size(); i++)  {
			cout << v[i] << endl;
		}
		cout << endl;
	}
	void test() {
		int n; 
		while (1)
		{
			cin >> n;
			print(solveNQueens(n));
		}
	}
};


int main() {
	Solution s;
	s.test();
}
