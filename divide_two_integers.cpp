/*************************************************************************
  > File Name: divide_two_integers.cpp
  > Author: lax
  > Mail: xingkungao@gmail.com
  > Created Time: Wed 10 Dec 2014 05:53:42 PM CST
 ************************************************************************/

#include "CPP.h"
#include "utility.h"
using namespace std;

class Solution {
	public:
		int divide(int dividend, int divisor) {
			long long a = dividend, b = divisor, c; 
			if (b == 0 || b == -1 && a == INT_MIN)
				return INT_MAX;

			int negative = 0;

			if (a < 0) {
				negative = 1 - negative;
				a = -a;
			}
			if (b < 0) {
				negative = 1 - negative;
				b = -b;
			}

			else if (b == 1)
				return (negative ? -a : a);

			int ret = 0;
			for (int i = 30; i >= 0 && a; i--) {
				c = (b << i);
				if (a >= c) { 
					a -= c;
					ret += (1 << i); 
				}
			}
			return (negative ? -ret : ret);
		}
		void test() {
			int a, b;
			cout << divide(INT_MAX, INT_MAX) << endl;
			cout << divide(INT_MIN, INT_MIN) << endl;
			cout << divide(INT_MIN, 0) << endl;
			while (1) {
				cin >> a >> b;
				cout << divide(a, b) << endl;
			}
		}
};
int main () {
	Solution s;
	s.test();
}
