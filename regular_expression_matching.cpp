/*************************************************************************
  > File Name: regular_expression_matching.cpp > Author: lax
  > Mail: xingkungao@gmail.com
  > Created Time: Fri 05 Dec 2014 09:57:45 PM CST
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
class Solution {
	public:
		/*
		bool isMatch(const char *s, const char *p) {
			const char *a = s, *b = p;
			char c;
			while (*b) {
				if (*b == '.') {
					s++;
					b++;
				}
				else if (*b == '*') {
					if (!(*(b+1)))
						return true;
					c = *(b-1);
					else if(*(b+1) == '.') {
						// find the char before *

					}
					else {
						if (c == '.') {
							while (*a) {
								if (*a == *(b+1))
									break;
								a++;
							}
							if (*a == 0)
								return false;
							else {
								a++;
								b++;
							}
						}
					}
					else {
						while () {
						}
					}
				}
				else if (*a != *b)
					return false;
			}
			return true;
		}
		*/

		/*dynamic programming approach, a neat way*/
		bool isMatch(const char *s, const char *p) {
			int n = strlen(s);
			int m = strlen(p);
			bool f[n+1][m+1];

			char c;
			f[0][0] = true;
			for (int i = 1; i <= n; i++)  {
				f[i][0] = false;
			}

			/* the following for loop is of great importance to get the right base cases */
			for (int i = 1; i <= m; i++) {
				f[0][i] = (p[i-1] == '*' && f[0][i-2]);
			}
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= m; j++) {
					switch (p[j-1]) {
						case '.':
							f[i][j] = f[i-1][j-1];
							break;
						case '*':
							c = p[j-2];
							/* two cases:
							 * 1)   p[j-1] is not used in this matching 
							 * 2)   p[j-1] is used in this matching, i.e. p[j-2] == '.' || p[j-2] == s[i-1] 
							 */
							f[i][j] = f[i][j-2] || (c == '.' ? true : c == s[i-1]) && f[i-1][j];
							break;
						default:
							f[i][j] = f[i-1][j-1] && s[i-1] == p[j-1];
					}
				}
			}
			return f[n][m];
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

