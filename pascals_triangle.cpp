/*************************************************************************
    > File Name: pascals_triangle.cpp
    > Author: lax
    > Mail: xingkungao@gmail.com
    > Created Time: Fri 12 Dec 2014 02:54:12 PM CST
 ************************************************************************/

#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;
class Solution {
	public:
		vector<vector<int> > generate(int numRows) {
			vector<vector<int> > r;
			for (int i = 0; i < numRows; i++)  {
				vector<int> v;
				v.push_back(1);
				if (i) {
					for (int j = 1; j < i; j++) 
						v.push_back(r[i-1][j-1] + r[i-1][j]);
					v.push_back(1);
				}
				r.push_back(v);
			}
			return r;
		}
		void print(vector<vector<int> > v) {
			for (int i = 0; i < v.size(); i++) {
				for (int j = 0; j < v[i].size(); j++) 
					cout << v[i][j] << " ";
				cout << endl;
			}
		}
		void test() {
			int n;
			while (1) {
				cin >> n;
				print(generate(n));
			}
		}
};

int main() {
	Solution s;
	s.test();
}
