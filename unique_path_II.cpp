/*************************************************************************
    > File Name: unique_path_II.cpp
    > Author: lax
    > Mail: xingkungao@gmail.com
    > Created Time: Fri 26 Dec 2014 10:12:09 PM CST
 ************************************************************************/

#include "CPP.h"
#include "utility.h"
using namespace std;

class Solution {
	public:
		int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
			int m = obstacleGrid.size();
			if (!m) return 0;
			int n = obstacleGrid[0].size();
			if (!n) return 0;
			vector<vector<int>> ret(m, vector<int>(n));
			ret[0][0] = 1 - obstacleGrid[0][0];
			for (int i = 1; i < m; i++)
				ret[i][0] = obstacleGrid[i][0] ? 0 : ret[i-1][0];
			for (int j = 1; j < n; j++)
				ret[0][j] = obstacleGrid[0][j] ? 0 : ret[0][j-1];
			for (int i = 1; i < m; i++) 
				for (int j = 1; j < n; j++) {
					if (obstacleGrid[i][j])
						ret[i][j] = 0;
					else 
						ret[i][j] = ret[i-1][j] + ret[i][j-1];
				}
			return ret[m-1][n-1];
		}
		void test() {
			vector<vector<int> > board(3, vector<int>(3, 0));
			board[1][1] = 1;
			cout << uniquePathsWithObstacles(board) << endl;
		}
};

int main() {
	Solution s;
	s.test();
}
