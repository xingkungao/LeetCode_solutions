/*************************************************************************
  > File Name: edit_distance.cpp
  > Author: lax
  > Mail: xingkungao@gmail.com
  > Created Time: Thu 11 Dec 2014 04:39:46 PM CST
 ************************************************************************/

#include <iostream>
#include <cstdio>
using namespace std;

class Solution {
	public:
		int minDistance(string word1, string word2) {
			int m = word1.length();
			int n = word2.length();
			int f[2][n+1];
			for (int i = 0; i <= n; i++)
				f[0][i] = i;
			f[1][0] = 1;
			int row;
			
			for (int i = 1; i <= m; i++) {
				row = i % 2;
				f[row][0] = i;
				for (int j = 1; j <= n; j++) {
					f[row][j] = min(1 + f[1-row][j], min(1 + f[row][j-1], (word1[i-1] == word2[j-1] ? 0 : 1) + f[1-row][j-1]));
				}
			}
			/*
			for (int i = 0; i <= n; i++)
				cout << f[m&1][i] << " ";
			cout << endl;
			*/
			return f[m&1][n];
		}
		void test() {
			string a, b;
			while (1) {
				cin >> a;
				cin >> b;
				cout << minDistance(a, b) << endl;
			}
		}

};

int main() {
	Solution s;
	s.test();
}
