/*************************************************************************
  > File Name: wildcard_matching.cpp
  > Author: lax
  > Mail: xingkungao@gmail.com
  > Created Time: Tue 16 Dec 2014 05:23:52 PM CST
 ************************************************************************/

#include "CPP.h"
#include "utility.h"
class Solution {
	public:
		bool isMatch(const char *s, const char *p) {
			int n = strlen(s);
			int m = strlen(p);
			bool f[2][m+1];
			int cnt;

			int i, j, row = 0;
			f[0][0] = true;
			f[1][0] = true;

			for (i = 0; i < m; i++) {
				if (p[i] != '*')
					break;
				else 
					f[0][i+1] = f[1][i+1] = true; 
			}
			cnt = i;
			for (i; i < m; i++) {
				f[0][i+1] = f[1][i+1] = false; 
				if (p[i] == '*')
					cnt++;
			}
			if (n < m - cnt) {
				return false;
			}

			//			print1DArray(f[0], m + 1);

			for (i = 0; i < n; i++) {
				row = i & 1;
				f[row][0] = false;
				for (j = 0; j < m; j++) {
					f[row][j+1] = false;
					if (p[j] == '?') 
						f[row][j+1] = f[1-row][j];
					else if (p[j] == '*') 
						f[row][j+1] = f[row][j] || f[1-row][j+1];
					else if (p[j] == s[i])  {
						f[row][j+1] = f[1-row][j];
					}
				}
//				print1DArray(f[row], m + 1);
			}
			return f[row][m];
		}
		void test() {
			string a, b;
			while (1) {
				cin >> a >> b;
				cout << boolalpha << isMatch(a.c_str(), b.c_str()) << endl;
			}
		}
};


int main() {
	Solution s;
	s.test();

}
