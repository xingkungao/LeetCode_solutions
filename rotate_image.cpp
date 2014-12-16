/*************************************************************************
  > File Name: rotate_image.cpp
  > Author: lax
  > Mail: xingkungao@gmail.com
  > Created Time: Tue 16 Dec 2014 08:05:17 PM CST
 ************************************************************************/

#include "CPP.h"
#include "utility.h"
using namespace std;

class Solution {
	public:
		void rotate(vector<vector<int> > &matrix) {
			int len = matrix.size();
			transpose(matrix);
			for (int i = 0;  i < len; i++) {
				reverse(matrix[i].begin(), matrix[i].end());
			}
		}
		void transpose(vector<vector<int> > &matrix) {
			int n = matrix.size();
			for (int i = 0; i < n; i++) 
				for (int j = i + 1; j < n; j++) 
					swap(matrix[i][j], matrix[j][i]);
		}
		void test() {
			int n, x;
			vector<vector<int> > v;
			cin >> n;
			for (int i = 0; i < n; i++) {
				vector<int> row;
				for (int j = 0; j < n; j++) {
					cin >> x;
					row.push_back(x);
				}
				v.push_back(row);
			}
			rotate(v);
			print2DVector(v);
		}
};


int main() {
	Solution s;
	s.test();
}
