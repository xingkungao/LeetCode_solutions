/*************************************************************************
    > File Name: pow_x_n.cpp
    > Author: lax
    > Mail: xingkungao@gmail.com
    > Created Time: Wed 10 Dec 2014 09:11:03 PM CST
 ************************************************************************/

#include <iostream>
#include <cstdio>
using namespace std;
class Solution {
	public:
		double pow(double x, int n) {
			if (n == 1 || x == 0)
				return x;
			if (n == 0 || x == 1)
				return 1;
			if  (n < 0) 
					return (1.0 / x / pow(x, -(n + 1)));
			int m = n / 2;
			double half = pow(x, m);
			double result = half * half;
			if (n % 2)
				return result * x;
			return result;
		}
		void test() {
			double x; 
			int n;
			while (1) {
				cin >> x; 
				cin >> n;
				cout << "ans is:" <<  pow(x, n) << endl;
			}
		}
};

int main() {
	Solution s;
	s.test();
}

