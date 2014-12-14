/*************************************************************************
  > File Name: subsets_II.cpp
  > Author: lax
  > Mail: xingkungao@gmail.com
  > Created Time: Sat 13 Dec 2014 02:11:09 PM CST
 ************************************************************************/

#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;

class Solution {
	public:
		vector<vector<int> > subsetsWithDup(vector<int> &a) {
			vector<vector<int> > v;
			vector<int> s(a);
			std::sort(s.begin(), s.end());
			vector<bool> flag(s.size(), false);
			subsetWithDupBacktracking(s, v, 0, flag);
			return v;
		}
		void subsetWithDupBacktracking(vector<int> &s, vector<vector<int> > &v, int pos, vector<bool> &flag) {
			int len = s.size();
			if (pos == len) {
				vector<int> line;
				for (int i = 0; i < len; i++)
					if (flag[i]) 
						line.push_back(s[i]);
				v.push_back(line);
				return;
			}

			int j = pos;
			do {
				flag[j] = false;
				j++;
			}while (j < len && s[pos] == s[j]);
			subsetWithDupBacktracking(s, v, j, flag);
			for (int i = pos; i < j; i++) {
				flag[i] = true;
				subsetWithDupBacktracking(s, v, j, flag);
			}
		}

		void print(vector<vector<int> > v) {
			for (int i = 0; i < v.size(); i++) {
				for (int j  = 0; j < v[i].size(); j++)
					cout << v[i][j] << " ";
				cout << endl;
			}
		}
		void test() {
			vector<int> v;
			int x;
			while (cin >> x) {
				if (x <= 0) {
					cout << "print\n";
					print(subsetsWithDup(v));
					v.clear(); 
				}
				else 
					v.push_back(x);
			}
		}
};

int main() {
	Solution s;
	s.test();
}
