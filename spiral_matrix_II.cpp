/*************************************************************************
    > File Name: spiral_matrix.cpp
    > Author: lax
    > Mail: xingkungao@gmail.com
    > Created Time: Sun 14 Dec 2014 08:32:53 PM CST
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
class Solution {
	public:
		vector<vector<int> > generateMatrix(int n) {
			vector<vector<int> > v;
			if (n < 0)
				return v;
			int i, j, k, l;
			for (i = 0; i < n; i++) {
				vector<int> row(n, 0);
				v.push_back(row);
			}

			i = j = -1;
			l = 1;
			for (k = 0; k < n / 2; k++) {
				for (j = j + 1, i = i + 1; j < n - k; j++)
					v[i][j] = l++;
				for (j = j - 1, i = i + 1; i < n - k; i++)
					v[i][j] = l++;
				for (j = j - 1, i = i - 1; j >= k; j--)
					v[i][j] = l++;
				for (i = i - 1, j = j + 1; i > k; i--)
					v[i][j] = l++;
		//		cout << "k:" << k << endl;
			//	print(v);
			}
			if (n&1)
				v[n/2][n/2] = l;
			return v;
		}
		void print(vector<vector<int> > v) {
			for (int i = 0; i < v.size(); i++) {
				for (int j = 0; j < v[i].size(); j++)
					cout << v[i][j] << '\t';
				cout << endl;
			}
		}
		void test() {
			int n;
			while (1) {
				cin >> n; 
				print(generateMatrix(n));
			}
		}
};
int main() {
	Solution s;
	s.test();
}
