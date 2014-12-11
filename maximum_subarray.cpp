/*************************************************************************
    > File Name: maximum_subarray.cpp
    > Author: lax
    > Mail: xingkungao@gmail.com
    > Created Time: Thu 11 Dec 2014 12:27:59 AM CST
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <climits>
using namespace std;
class Solution {
	public:
		int maxSubArray(int A[], int n) {
			int m = INT_MIN, result = INT_MIN; 
			for (int i = 0; i < n; i++) {
				if (m < 0)
					m = A[i];
				else 
					m += A[i];
				result = std::max(m, result);
			}
			return result;
		}
		void test() {
			int a[100];
			int n;
			while (1) {
				cin >> n;
				for (int i = 0; i < n; i++)
					cin >> a[i];
				cout << maxSubArray(a, n) << endl;
			}
		}
};

int main() {
	Solution s;
	s.test();
}
