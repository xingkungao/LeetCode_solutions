/*************************************************************************
  > File Name: first_missing_positive.cpp
  > Author: lax
  > Mail: xingkungao@gmail.com
  > Created Time: Thu 01 Jan 2015 04:39:29 PM CST
 ************************************************************************/

#include "CPP.h"
#include "utility.h"
using namespace std;

class Solution {
	public:
		int firstMissingPositive(int A[], int n) {
			for (int i = 0; i < n; ++i) {
				int d = A[i];
				while (d >= 1 && d <= n && A[d-1] != d) {
					swap(A[d-1], A[i]);
					d = A[i];
				}
			}
			for (int i = 0; i < n; i++) 
				if (A[i] != i + 1)
					return i + 1;
			return n + 1;
		}
		void test() {
		}
};

int main() {
	Solution s;
	s.test();
}
