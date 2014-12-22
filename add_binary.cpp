/*************************************************************************
  > File Name: add_binary.cpp
  > Author: lax
  > Mail: xingkungao@gmail.com
  > Created Time: Mon 22 Dec 2014 04:52:28 PM CST
 ************************************************************************/

#include "CPP.h"
#include "utility.h"
using namespace std;

class Solution {
	public:
		string addBinary(string a, string b) {
			int la = a.length() - 1, lb = b.length() - 1;
			string res;
			int carry = 0, digit;
			while (la >= 0 || lb >= 0) {
				digit = carry;
				if (la >= 0) { 
					digit += a[la] - '0'; 
					la--;
				}
				if (lb >= 0) {
					digit += b[lb] - '0';
					lb--;
				}
				carry = digit / 2;
				res.push_back(digit % 2 + '0');
			}
			if (carry)
				res.push_back(carry + '0');
			reverse(res.begin(), res.end());
			return res;
		}
		void test() {
			string a, b;
			while (1) {
				cin >> a >> b;
				cout << addBinary(a, b) << endl;
			}
		}
};

int main() {
	Solution s;
	s.test();
}
