/*************************************************************************
    > File Name: minimum_path_sum.cpp
    > Author: lax
    > Mail: xingkungao@gmail.com
    > Created Time: Fri 26 Dec 2014 10:45:20 PM CST
 ************************************************************************/

#include "CPP.h"
#include "utility.h"
using namespace std;

class Solution {
	public:
		int minPathSum(vector<vector<int> > &grid) {
			int m = grid.size();
			if (!m)
				return 0;
			int n = grid[0].size();
			if (!n)
				return 0;
			vector<vector<int> > ret(m, vector<int>(n));
			ret[0][0] = grid[0][0];
			for (int i = 1; i < n; i++)
				ret[0][i] = ret[0][i-1] + grid[0][i];
			for (int i = 1; i < m; i++)
				ret[i][0] = ret[i-1][0] + grid[i][0];
			for (int i = 1; i < m; i++)
				for (int j = 1; j < n; j++)
					ret[i][j] = grid[i][j] + min(ret[i-1][j], ret[i][j-1]);
			return ret[m-1][n-1];
		}
		void test() {
			vector<vector<int> > grid(3, vector<int>(3));
			grid[0][0] = 1;
			grid[0][1] = 2;
			grid[0][2] = 3;
			grid[1][0] = 4;
			grid[1][1] = 1;
			grid[1][2] = 4;
			grid[2][0] = 4;
			grid[2][1] = 1;
			grid[2][2] = 0;
			cout << minPathSum(grid) << endl;
		}
};

int main() {
	Solution s;
	s.test();
}
