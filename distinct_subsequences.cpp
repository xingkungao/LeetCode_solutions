/*************************************************************************
  > File Name: distinct_subsequences.cpp
  > Author: lax
  > Mail: xingkungao@gmail.com
  > Created Time: Mon 05 Jan 2015 04:28:01 PM CST
 ************************************************************************/

#include "CPP.h"
#include "utility.h"
using namespace std;

class Solution {
	public:
		int numDistinct(string S, string T) {
			int n = S.length();
			int m = T.length();
			int ret[m + 1];
			for (int i = 0; i <= m; i++)
				ret[i] = 0;
			for (int i = 1; i <= n; i++) {
				ret[0] = 1;
				for (int j = min(m, i); j >= 1; j--)
					if (S[i-1] == T[j-1])
						ret[j] += ret[j-1];
			}
			return ret[m];
		}

		void test() {
			string a, b;
			while (1) {
				cin >> a >> b;
				cout << numDistinct(a, b) << endl;
			}
		}
};

int main() {
	Solution s;
	s.test();
}
