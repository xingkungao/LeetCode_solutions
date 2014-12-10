/*************************************************************************
    > File Name: sqrt(x).cpp
    > Author: lax
    > Mail: xingkungao@gmail.com
    > Created Time: Mon 08 Dec 2014 09:11:42 PM CST
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <climits>
using namespace std;
class Solution {
	public:
		/* binary search */
		int sqrt(int x) {
			int l = 0, r = x;
			long long mid;
			long long mul;
			while (l <= r) {
				mid = (l + r) / 2;
				mul = mid * mid;
				if (mul < x)
					l = mid + 1;
				else if (mul > x)
					r = mid - 1;
				else 
					return mid;
			}
			return  (l + r) /2;
		}
		/* babylonian method */
		int sqrt2(int x) {
			long long ans = x / 2;
			if (!ans)
				return x;
			long long mul, less, more;
			while (1) {
				ans = (ans + x / ans) / 2;
				mul = ans * ans;
				less = mul -2 * ans + 1; 
				more = less + 4 * ans;
				if (mul == x)
					return ans;
				else if (less < x && mul > x)
					return ans - 1;
				else if (mul < x && more > x)
					return ans;
			}

		}
		/* newton's method */
		/* f(x) = x * x - s;
		 * x_(k+1) = x_(k) - f(x(k)) / df(x(k)) = (x(k) + s/x(k)) / 2
		 * it turns out that it's the same with babylonian method
		 */
		int sqrt3(int x) {
			return sqrt2(x);
		}
		void test() {
			int x;
			while (1) {
				cin >> x;
				cout << sqrt(x) << ' ' << sqrt2(x)<< endl;
			}
		}
};

int main() {
	Solution s;
	s.test();
}

