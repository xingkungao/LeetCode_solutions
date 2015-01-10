/*************************************************************************
  > File Name: dungeon_game.cpp
  > Author: lax
  > Mail: xingkungao@gmail.com
  > Created Time: Sat 10 Jan 2015 04:49:07 PM CST
 ************************************************************************/

#include "CPP.h"
#include "utility.h"
using namespace std;

class Solution {
	public:
		int calculateMinimumHP(vector<vector<int> > &dungeon) {
			int m = dungeon.size();
			int penalty;
			if (!m)
				return -1;
			int n = dungeon[0].size();
			/*row[k][i] = min(row[k+1][i], row[k][i+1])
			*/
			int row[n+1];
			for (int i = 0; i <= n; i++)
				row[i] = ((INT_MAX) >> 1);

			for (int i = m - 1; i >= 0; i--) {
				for (int j = n - 1; j >= 0; j--) {
					penalty = dungeon[i][j];
					if (i == m-1 && j == n-1)
						row[j] = max(-penalty, 0);
					else 
						row[j] = min(max(row[j+1] - penalty, 0), max(row[j] - penalty, 0));
				}
				for (int j = 0; j < n; j++)
					cout << row[j] << '\t';
				cout << endl;
			}
			return row[0] + 1;
		}
		void test() {
			vector<vector<int> > dungeon(3, vector<int>(3, 0));
			dungeon[0][0] = -2;
			dungeon[0][1] = -3;
			dungeon[0][2] = 3;

			dungeon[1][0] = -5;
			dungeon[1][1] = -10;
			dungeon[1][2] = 1;

			dungeon[2][0] = 10;
			dungeon[2][1] = 30;
			dungeon[2][2] = -5;
			cout << calculateMinimumHP(dungeon) << endl;
		}
};

int main() {
	Solution s;
	s.test();
}

