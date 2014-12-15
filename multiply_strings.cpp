/*************************************************************************
    > File Name: multiply_strings.cpp
    > Author: lax
    > Mail: xingkungao@gmail.com
    > Created Time: Mon 15 Dec 2014 05:22:16 PM CST
 ************************************************************************/

#include "CPP.h"
#include "utility.h"
using namespace std;

class Solution {
	public:
		string multiply(string num1, string num2) {
			int len1 = num1.length();
			int len2 = num2.length();
			int len = len1 + len2;
			int m, c, d;
			string ret(len, '0');
			for (int i = len2 - 1; i >= 0; i--) {
				c = 0;
				for (int j = len1 - 1; j >= 0; j--) {
					d = ret[i+j+1] - '0';
					m = c + d + (num2[i] - '0') * (num1[j] - '0');
					c = m / 10;
					ret[i+j+1] = m % 10 + '0';
				}
				if (c) 
					ret[i] = c + '0';
			}
			int i = 0;
			while (i < len - 1) {
				if (ret[i] == '0')
					i++;
				else 
					break;
			}
			return ret.substr(i, len - i);
		}
		void test() {
			string s1, s2;
			while (1) {
				cin >> s1;
				cin >> s2; 
				cout << multiply(s1, s2) << endl;
			}
		}
};

int main() {
	Solution s;
	s.test();
}
