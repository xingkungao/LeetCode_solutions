/*************************************************************************
    > File Name: maximum_product_subarray.cpp
    > Author: lax
    > Mail: xingkungao@gmail.com
    > Created Time: Tue 02 Dec 2014 02:28:31 PM CST
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <climits>
using namespace std;
class Solution {
	public:
		int maxProduct(int A[], int n) {
			int tmp;
			int cmax = A[0];
			int cmin = A[0];
			int rmax = cmax;
			for (int i = 1; i < n; i++) {
				if (A[i] < 0) {
					tmp = cmax;
					cmax = std::max(A[i], cmin * A[i]);
					cmin = std::min(A[i], tmp * A[i]);
				}
				else {
					cmin = std::min(A[i], cmin * A[i]);
					cmax = std::max(A[i], cmax * A[i]);
				}
				rmax = std::max(rmax, cmax);
			}
			return rmax;
		}
};
int main() {
	Solution s;
	int a[6] = {-4,-3,-2};
	cout << s.maxProduct(a, 3) << endl;
}

