/*************************************************************************
  > File Name: decode_ways.cpp
  > Author: lax
  > Mail: xingkungao@gmail.com
  > Created Time: Tue 16 Dec 2014 02:59:31 PM CST
 ************************************************************************/

#include "CPP.h"
#include "utility.h"
class Solution {
	public:
		int numDecodings(string s) {
			int len = s.length();
			if (!len)
				return 0;
			int f[len+1], a, b;
			f[0] = 1; 
			if (s[0] - '0' > 0 && s[0] - '0' <= 9)
				f[1] = 1;
			else
				f[1] = 0;
			for (int i = 1; i < len; i++) {
				b = s[i] - '0';
				f[i+1] = 0;
				if (b >= 0 && b <= 9) {
					a = s[i-1] - '0';
					if (b >= 1) {
						f[i+1] += f[i]; 
					}
					if (a == 1 || a == 2  && b <= 6) {
						f[i+1] += f[i-1]; 
					}
				}
			}
			return f[len];
		}

		void test() {
			string s;
			while (1) {
				cin >> s;
				for (int i = 0; i < s.length(); i++)
					s[i] = toupper(s[i]);
				cout << numDecodings(s) << endl;
			}
		}
};

int main() {
	Solution s;
	s.test();
};
