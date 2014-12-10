/*************************************************************************
    > File Name: climbing_stairs.cpp
    > Author: lax
    > Mail: xingkungao@gmail.com
    > Created Time: Mon 08 Dec 2014 10:24:00 PM CST
 ************************************************************************/

#include <iostream>
#include <cstdio>
using namespace std;
class Solution {
	public:
		int climbStairs(int n) {
			int a = 1, b = 1, t;
			for (int i = 2; i <= n; i++)  {
				t = b;
				b = a + b;
				a = t;
			}
			if (!n || n == 1)
				return 1;
			return b;
		}
		void test() {
			int x;
			while (1) {
				cin >> x;
				cout << climbStairs(x) << endl;
			}
		}

};

int main() {
	Solution s;
	s.test();
}
