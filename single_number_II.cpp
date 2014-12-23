/*************************************************************************
    > File Name: single_number_II.cpp
    > Author: lax
    > Mail: xingkungao@gmail.com
    > Created Time: Tue 23 Dec 2014 02:07:15 PM CST
 ************************************************************************/

#include "CPP.h"
#include "utility.h"
using namespace std;

class Solution {
	public:
		int singleNumber(int A[], int n) {
			int zero = 0, one = 0;
			for (int i = 0; i < n; i++) {
				zero = (zero ^ A[i]) & ~one;
				one = (one ^ A[i]) & ~zero;
			}
			return one^zero;
		}

		void test() {
			int a[100];
			int n;
			while (1) {
				cin >> n;
				for (int i = 0; i < n; i++)
					cin >> a[i];
				cout << singleNumber(a, n) << endl;
			}
		}

};

int main() {
	Solution s;
	s.test();
}
