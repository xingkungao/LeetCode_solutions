/*************************************************************************
    > File Name: longest_palindromic_substring.cpp
    > Author: lax
    > Mail: xingkungao@gmail.com
    > Created Time: Mon 08 Dec 2014 01:47:12 PM CST
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
class Solution {
	public:
		/* Dynamic Programming approach O(n^2) */ 
		string longestPalindrome(string s) {
			int len = s.length();
			bool f[len][len];
			for (int i = len -1; i >= 0; i--) {
				f[i][i] = true;
				for (int j = i + 1; j < len; j++) {
					f[i][j] = s[j] == s[i];
					if (j > i + 1)
						f[i][j] = f[i][j] && f[i+1][j-1];
				}
			}
			/*
			for (int i = 0; i < len; i++) {
				for (int j = 0; j < len; j++)
					cout << boolalpha << f[i][j] <<'\t';
				cout << endl;
			}
			*/

			int l, r, R, L;
			L = R = 0;

			for (int i = 0; i < len; i++) {
				l = i;
				for (int j = len - 1; j >= 0; j--)
					if (f[i][j]) {
						r = j;
						break;
					}
				if (R - L < r - l) {
					R = r;
					L = l;
				}
			}
			return s.substr(L, R + 1 - L);
		}
		void test() {
			string s;
			while (1) {
				cin >> s;
				cout << longestPalindrome(s) << endl;
			}
		}
};

int main() {
	Solution s;
	s.test();
}

