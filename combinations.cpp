/*************************************************************************
  > File Name: combinations.cpp
  > Author: lax
  > Mail: xingkungao@gmail.com
  > Created Time: Fri 12 Dec 2014 04:18:21 PM CST
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
class Solution {
	public:
		vector<vector<int> > combine(int n, int k) {
			vector<vector<int> > v;
			vector<bool> flag(n, false);
			combineBacktracking(v, flag, 0, k, 0);
			return v;
		}
		void combineBacktracking(vector<vector<int> > &v, vector<bool> &flag, int pos, int k, int cnt) {
			int len = flag.size();
			if (cnt == k) {
				vector<int> line;
				for (int i = 0; i < len; i++)  {
					if (flag[i])
						line.push_back(i+1);
				}
				v.push_back(line);
				return;
			}
			for (int i = pos; i < len; i++) {
				if(!flag[i]) {
					flag[i] = true;
					combineBacktracking(v, flag, i+1, k, cnt+1);
					flag[i] = false;

				}
			}
		}
		void print(vector<vector<int> > v) {
			for (int i = 0; i < v.size(); i++) {
				for (int j = 0; j < v[i].size(); j++)
					cout << v[i][j] << " " ;
				cout << endl;
			}
		}

		void test() {
			int n, k;
			while (1) {
				cin >> n;
				cin >> k;
				cout << "print:\n";
				print(combine(n, k));
			}
		}
};

int main() {
	Solution s;
	s.test();
}

