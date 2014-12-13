/*************************************************************************
    > File Name: pascals_triangle_II.cpp
    > Author: lax
    > Mail: xingkungao@gmail.com
    > Created Time: Fri 12 Dec 2014 03:11:00 PM CST
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
class Solution {
	public:
		vector<int> getRow(int rowIndex) {
			rowIndex++;
			vector< vector<int> > v;
			vector<int> tmp(rowIndex + 1, 1);
			v.push_back(tmp);
			v.push_back(tmp);
			int row;
			for (int i = 2; i < rowIndex; i++) {
				row = i & 1;
				for (int j = 1; j < i; j++)
					v[row][j] = v[1-row][j-1] + v[1-row][j];
			}
			tmp = v[1 - (rowIndex & 1)];
			for (int i = rowIndex; i < tmp.size(); i++)
				tmp.pop_back();
			return tmp;
		}
		void print(vector<int> v) {
			for (int i = 0; i < v.size(); i++)
				cout << v[i] << " ";
			cout << endl;
		}
		void test() {
			int n;
			while (1) {
				cin >> n;
				print(getRow(n));
			}
		}
};

int main() {
	Solution s;
	s.test();
}
