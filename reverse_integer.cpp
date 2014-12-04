/*************************************************************************
    > File Name: reverse_integer.cpp
    > Author: lax
    > Mail: xingkungao@gmail.com
    > Created Time: Thu 04 Dec 2014 12:59:27 AM CST
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <climits>
using namespace std;
class Solution {
	public:
		int reverse(int x) {
			bool tag = false;
			bool of = false;
			if (x < 0) {
				if (x == INT_MIN)
					return 0;
				x = -x;
				tag = true;
			}
			int q, r;
			long long ans = 0;
			while (x) {
				r = x % 10;
				x = x / 10;
				ans = ans * 10 + r;
				if ( !tag && ans > INT_MAX || tag && ans  - 1> INT_MAX ) {
					of = true;
					break;
				}
			}
			if (tag)
				ans = -ans;
			if (of)
				ans = 0;
			return ans;
		}
		void test() {
			int x;
			while (1) {
			cin >> x;
			cout << x << endl;
			cout << reverse(x) << endl;
			}
		}
};

int main() {
	Solution s;
	cout << INT_MIN << endl;
	s.test();
}
