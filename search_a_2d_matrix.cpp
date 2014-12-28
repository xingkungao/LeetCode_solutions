/*************************************************************************
  > File Name: search_a_2d_matrix.cpp
  > Author: lax
  > Mail: xingkungao@gmail.com
  > Created Time: Sun 28 Dec 2014 05:11:26 PM CST
 ************************************************************************/

#include "CPP.h"
#include "utility.h"
using namespace std;

class Solution {
	public:
		bool searchMatrix(vector<vector<int> > &matrix, int target) {
			int m = matrix.size();
			if (!m)
				return false;
			int n = matrix[0].size();
			int l, r, mid;
			l = 0; 
			r = m * n -1;
			while (l < r) {
				mid = (l + r)/2;
				if (matrix[mid/n][mid%n] >= target)
					r = mid;
				else 
					l = mid  + 1;
			}
			return matrix[l/n][l%n] == target;
		}
		void test(){
			vector<vector<int> > matrix;
			vector<int> row;
			int m, n, x;
			cin >> m >> n;
			for (int i = 0; i < m; i++) {
				for (int j = 0; j < n; j++) {
					cin >> x;
					row.push_back(x);
				}
				matrix.push_back(row);
				row.clear();
			}
			int target;
			while (1) {
				cin >> target;
				cout << boolalpha << searchMatrix(matrix, target) << endl;
			}

		}
};

int main() {
	Solution s;
	s.test();
}
