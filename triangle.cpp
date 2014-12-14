/*************************************************************************
  > File Name: triangle.cpp
  > Author: lax
  > Mail: xingkungao@gmail.com
  > Created Time: Sun 14 Dec 2014 04:36:04 PM CST
 ************************************************************************/

#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;
class Solution {
	public:
		int minimumTotal(vector<vector<int> > &triangle) {
			int level = triangle.size();
			if (!level)
				return 0;
			int len =  triangle.back().size();
			if (!len)
				return 0;

			vector<int> v(len+2, 0);
			vector<vector<int> > value;
			value.push_back(v);
			value.push_back(v);

			int row;
			for (int i = level - 1; i >= 0; i--) {
				row = i & 1;
				for (int j = 0; j <= level; j++) {
					value[row][j] = triangle[i][j] + min(value[1-row][j], value[1-row][j+1]);
				}
				/*
				cout << i << ":      ";
				for (int j = 0; j <= level; j++)
					cout << value[row][j] << ' ';
				cout << endl;
				*/
			}
			return value[row][0];
		}

		void test() {
			vector<vector<int> > v;
			vector<int> l0;
			vector<int> l1;
			vector<int> l2;
			vector<int> l3;

			l0.push_back(-1);
			v.push_back(l0);

			l1.push_back(2);
			l1.push_back(3);
			v.push_back(l1);

			l2.push_back(1);
			l2.push_back(-1);
			l2.push_back(-3);
			v.push_back(l2);
			/*

			l3.push_back(4);
			l3.push_back(1);
			l3.push_back(8);
			l3.push_back(3);
			v.push_back(l3);
			*/

			cout << minimumTotal(v) << endl;

		}
};

int main() {
	Solution s;
	s.test();
}

