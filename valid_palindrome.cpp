/*************************************************************************
  > File Name: valid_palindrome.cpp
  > Author: lax
  > Mail: xingkungao@gmail.com
  > Created Time: Fri 12 Dec 2014 02:27:54 PM CST
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cctype>
using namespace std;
class Solution {
	public:
		bool isPalindrome(string s) {
			int l = 0, r = s.length() - 1;
			while (l <= r) {
				if (isalnum(s[l]) && isalnum(s[r])){
					if (tolower(s[l]) != tolower(s[r]))
						return false;
					l++;
					r--;
				}
				else if (!isalnum(s[l]))
					l++;
				else if (!isalnum(s[r]))
					r--;
			}
			return true;
		}
		void test() {
			string s;
			while (1) {
				getline(cin, s);
				cout << boolalpha << isPalindrome(s) << endl;
			}
		}
};

int main() {
	Solution s;
	s.test();
}

