/*************************************************************************
  > File Name: subsets.cpp
  > Author: lax
  > Mail: xingkungao@gmail.com
  > Created Time: Mon 15 Dec 2014 09:25:04 PM CST
 ************************************************************************/

#include "CPP.h"
#include "utility.h"
using namespace std;
class Solution {
	public:
		vector<vector<int> > subsets(vector<int> &S) {
			sort(S.begin(), S.end());
			vector<vector<int> > v;
			vector<bool> flag(S.size(), false);
			subsetsRecursive(S, v, flag, 0);
			return v; 
		}
		void subsetsRecursive(vector<int> &S, vector<vector<int> > &v, vector<bool> &flag, int l) {
			int len = S.size();
			if (l == len) {
				vector<int> line;
				for (int i = 0; i < len; i++)
					if (flag[i])
						line.push_back(S[i]);
				v.push_back(line);
			}
			else {
				flag[l] = false;
				subsetsRecursive(S, v, flag, l+1);
				flag[l] = true;
				subsetsRecursive(S, v, flag, l+1);
			}
		}
		void test() {
			vector<int> v;
			v.push_back(1);
			v.push_back(3);
			v.push_back(-1);
			v.push_back(10);
			print2DVector<int>(subsets(v));
		}
};


int main() {
	Solution s;
	s.test();
}
