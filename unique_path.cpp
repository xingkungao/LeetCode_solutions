/*************************************************************************
  > File Name: unique_path.cpp
  > Author: lax
  > Mail: xingkungao@gmail.com
  > Created Time: Fri 26 Dec 2014 09:50:47 PM CST
 ************************************************************************/

#include "CPP.h"
#include "utility.h"
using namespace std;

class Solution {
	public:
		int uniquePaths(int m, int n) {
			// (m+n-2) choose (m-1)
			m--;
			n--;
			vector<vector<int>> composition(2, vector<int>(200, 1));
			int row = 0;
			for (int i = 1; i <= m + n; i++) {
				row = i & 1;
				for (int j = 1; j <= i / 2; j++) {
					composition[row][i-j] = composition[row][j] = composition[1-row][j-1] + composition[1-row][j];
				}
			}
			return composition[row][m];
		}
		void test() {
			int m, n;
			while (1) {
				cin >> m >> n;
				cout << uniquePaths(m, n) << endl;
			}
		}
};

int main() {
	Solution s;
	s.test();
}
