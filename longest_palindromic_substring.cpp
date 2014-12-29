/*************************************************************************
  > File Name: longest_palindromic_substring.cpp
  > Author: lax
  > Mail: xingkungao@gmail.com
  > Created Time: Mon 08 Dec 2014 01:47:12 PM CST
 ************************************************************************/

#include "CPP.h"
#include "utility.h"
using namespace std;
class Solution {
	public:
		string longestPalindrome(string s) {
			return longestPalindrome2(s);
		}
		/* Dynamic Programming approach
		 * time complexity: O(n^2)
		 * space complexity: O(n^2)
		 * */ 
		string longestPalindrome0(string s) {
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
		/* a naive approach, expand every letter as center
		 * time complexity: O(n^2)
		 * space complexity: O(1)
		 * */ 
		string longestPalindrome1(string s) {
			int len = s.length();
			int L, R, l, r;
			L = R = 0;
			for (int i = 0; i < s.length(); i++) {
				expand(s, i, i, l, r);
				if (l - r < L - R) {
					L = l;
					R = r;
				}
				expand(s, i, i+1, l, r);
				if (l - r < L - R) {
					L = l;
					R = r;
				}
			}
			return s.substr(L, R + 1 - L);

		}
		void expand(const string &s, int l, int r, int &L, int &R) {
			int n = s.length();
			L = R = l;
			if (r >= n)
				return;

			while (l >= 0 && r < n) {
				if (s[l] == s[r]) {
					l--;
					r++;
				}
				else
					break;
			}
			L = l + 1;
			R = r - 1;
		}
		/* Manacher's algorithm
		 * time complexity: O(n)
		 * space complexity: O(1)
		 * */ 
		string longestPalindrome2(string a) {
			string s;
			s.push_back('$');
			for (int i = 0; i < a.length(); i++) {
				s.push_back(a[i]);
				s.push_back('$');
			}

			int len = s.length();
			int bound = 0, idx = 0;
			vector<int> table(len, 0);
			for (int i = 1; i < len; i++) {
				table[i] = bound > i ? min(table[2*idx - i], bound -i) : 1;
				while(i + table[i] < len && i - table[i] >= 0 && s[i+table[i]] == s[i-table[i]]) {
					table[i]++;
				}
				if(i + table[i] > bound) {
					bound = i + table[i];
					idx = i;
				}
			}
			int L = 0, Len = 0;
			for (int i = 0; i < len; i++) {
				if (Len < table[i]) {
					Len = table[i];
					L = i;
				}
			}
			L = (L- Len + 1);
			if (s[L] == '$')
				L++;
			return a.substr(L/2, Len-1);
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

