/*************************************************************************
  > File Name: spiral_matrix.cpp
  > Author: lax
  > Mail: xingkungao@gmail.com
  > Created Time: Mon 15 Dec 2014 12:16:00 AM CST
 ************************************************************************/

#include "CPP.h"
using namespace std;

class Solution {
	public:
		vector<int> spiralOrder(vector<vector<int> > &matrix) {
			int m = matrix.size();
			vector<int> ret;
			if (!m)
				return ret;
			int n = matrix[0].size();
			int i, j, k, l = min(m, n);
			i = j = -1;
			for (k = 0; k < l / 2; k++) {
				for (i = i + 1, j = j + 1; j < n - k; j++)
					ret.push_back(matrix[i][j]);
				for (i = i + 1, j = j - 1; i < m - k; i++)
					ret.push_back(matrix[i][j]);
				for (i = i - 1, j = j - 1; j >= k; j--)  
					ret.push_back(matrix[i][j]);
				for (i = i - 1, j = j + 1; i > k; i--)
					ret.push_back(matrix[i][j]);
			}
			if (l&1) {
				if (m <= n)
					for (i = i+1, j = j + 1; j < n - k; j++)
						ret.push_back(matrix[i][j]);
				else 
					for (i = i+1, j = j + 1; i < m - k; i++)
						ret.push_back(matrix[i][j]);

			}
			return ret;
		}
};
int main() {

	Solution s;
}
