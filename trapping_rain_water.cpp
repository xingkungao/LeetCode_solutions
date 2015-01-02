/*************************************************************************
  > File Name: trapping_rain_water.cpp
  > Author: lax
  > Mail: xingkungao@gmail.com
  > Created Time: Thu 01 Jan 2015 09:09:16 PM CST
 ************************************************************************/

#include "CPP.h"
#include "utility.h"
using namespace std;

class Solution {
	public:
		int trap(int A[], int n) {
			int ret = 0;
			int l = 0, r = n - 1, lmax = 0, rmax = 0;
			while (l <= r) {
				lmax = max(A[l], lmax);
				rmax = max(A[r], rmax);
				if (lmax <= rmax) {
					ret += lmax - A[l];
					l++;
				}
				else {
					ret += rmax - A[r];
					r--;
				}
			}
			return ret;
		}
		void test() {
			int a[100];
			int n;
			while (1) {
				cin >> n;
				for (int i = 0; i < n; i++)
					cin >> a[i];
				cout << trap(a, n) << endl;
			}
		}
};

int main() {
	Solution s;
	s.test();
}
