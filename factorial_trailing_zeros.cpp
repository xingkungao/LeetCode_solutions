/*************************************************************************
    > File Name: factorial_trailing_zeros.cpp
    > Author: lax
    > Mail: xingkungao@gmail.com
    > Created Time: Tue 30 Dec 2014 10:59:53 AM CST
 ************************************************************************/

#include "CPP.h"
#include "utility.h"
using namespace std;

class Solution {
	public:
		int trailingZeros(int n) {
			if (n <= 0)
				return 0;
			int cnt = 0;
			int divisor = 5;
			while (n >= divisor) {
				cnt += n / divisor;
				divisor *= 5;
			}
			return cnt;
		}
		void test() {
			int n;
			while (1) {
				cin >> n;
				cout << trailingZeros(n) << endl;
			}
		}
};

int main() {
	Solution s;
	s.test();
}
