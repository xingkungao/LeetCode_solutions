/*************************************************************************
  > File Name: length_of_last_word.cpp
  > Author: lax
  > Mail: xingkungao@gmail.com
  > Created Time: Sun 14 Dec 2014 07:43:59 PM CST
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
class Solution {
	public:
		int lengthOfLastWord(const char *s) {
			if (!s)
				return 0;
			const char *p = s;
			int ret = 0;
			int a = -1, b = -1, n = 0;
			while (1) {
				if (!(*p)) {
					if (b > a)
						ret = b - a;
					break;
				}
				else if (*p == ' '){
					if (p > s && *(p-1) != ' ') {
						ret = b - a;
					}
					a = n;
				}
				else {
					b = n;
				}
				p++;
				n++;
			}
			return ret;
		}
		int lengthOfLastWord1(const char *s) {
			int len = strlen(s);
			const char *a = s + len - 1;
			while(a >= s && *a == ' ')
				a--;
			if (a < s)
				return 0;
			int n  = 0;
			while (a >= s && *a != ' ') {
				n++;
				a--;
			}
			return n;
		}
		void test() {
			char *a = "a             ";
			char *b = "          ";
			char *c = "    ab fdf aaaaa   ";
			char *d = " s      aaa";
			char *e = "saaaaa";
			cout << lengthOfLastWord(a) << endl;
			cout << lengthOfLastWord(b) << endl;
			cout << lengthOfLastWord(c) << endl;
			cout << lengthOfLastWord(d) << endl;
			cout << lengthOfLastWord(e) << endl;
		}
};
int main() {
	Solution s;
	s.test();
}

