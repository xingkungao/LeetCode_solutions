/*************************************************************************
    > File Name: palindrome_number.cpp
    > Author: lax
    > Mail: xingkungao@gmail.com
    > Created Time: Fri 05 Dec 2014 09:20:01 PM CST
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <climits>
using namespace std;

class Solution {
	public:
		bool isPalindrome(int x) {
			if (x < 0)
				return false;
			int len = length(x);
			for (int i = 0; i < len / 2; i++) 
				if (getBit(x, i) != getBit(x, len - 1 - i))
					return false;
			return true;
		}
		int length(int x) {
			if (!x)
				return 1;

			int len = 0;
			int r;
			while (x) {
				r = x% 10;
				x /= 10;
				len ++;
			}
			return len;
		}
		void test() {
			int x; 
			while (1) {
				cin >> x;
				cout << boolalpha << isPalindrome(x) << endl;
			}
		}
		int getBit(int x, int i) {
			int mul = 1;
			for (int j = 0; j < i; j++)
				mul *= 10;
			return (x / mul) % 10; 
		}
};


int main() {
	Solution s;
	s.test();
}
