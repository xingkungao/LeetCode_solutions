/*************************************************************************
    > File Name: single_number.cpp
    > Author: lax
    > Mail: xingkungao@gmail.com
    > Created Time: Wed 03 Dec 2014 09:30:54 PM CST
 ************************************************************************/

#include <iostream>
#include <cstdio>
using namespace std;
class Solution {
	public:
		int singleNumber(int A[], int n) {
			int ans = 0;
			for (int i = 0; i < n; i++)
				ans ^= A[i];
			return ans;
		}
		void test() {
			int a[9] = {1,2,3,4,-1,4,3,2,1};
			cout << singleNumber(a, 9);
		}
};
int main() {
	Solution s;
	s.test();
}

