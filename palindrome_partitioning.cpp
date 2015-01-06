/*************************************************************************
  > File Name: palindrome_partitioning.cpp
  > Author: lax
  > Mail: xingkungao@gmail.com
  > Created Time: Tue 06 Jan 2015 04:43:06 PM CST
 ************************************************************************/

#include "CPP.h"
#include "utility.h"
using namespace std;

class Solution {
	public:
		vector<vector<string> > partition(string s) {
			int len = s.length();
			if (!len)
				return vector<vector<string>>();
			vector<vector<string> > ret[len+1];
			bool flag[len][len];
			for (int i = 0; i < len; i++) {
				flag[i][i] = true;
				for (int j = i - 1; j >= 0; j--) {
					flag[j][i] = (s[j] == s[i]);
					if (j + 1 <= i - 1) 
						flag[j][i] = flag[j][i] && flag[j+1][i-1];
				}
			}

			ret[0] = vector<vector<string> >();
			for (int i = 1; i <= len; i++) {
				ret[i] = vector<vector<string> >();
				for (int j = 1; j <= i; j++) {
					if (flag[j-1][i-1]) {
						if (ret[j-1].empty()) {
							ret[i].push_back(vector<string>(1, s.substr(j-1, i - j + 1)));
						}
						for (int k = 0; k < ret[j-1].size(); k++) {
							vector<string> tmp = ret[j-1][k];
							tmp.push_back(s.substr(j-1, i - j + 1));
							ret[i].push_back(tmp);
						}
					}
				}
			}
			return ret[len];
		}
		/*
		   void backTrace(vector<vector<string> > &ret, bool *flag[], string s, int l, int r) {
		   for (int i = l; i <= r; i++)
		   if (flag[i][r]) {
		   backTrace(ret, flag, s, l, i - 1);
		   string line = s.substr(i, r - i + 1) +  
		   }
		   }
		   */
		void test() {
			string s;
			while (1) {
				cin >> s;
				print2DVector(partition(s));
			}
		}
};

int main() {
	Solution s;
	s.test();
}

