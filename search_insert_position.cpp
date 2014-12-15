/*************************************************************************
  > File Name: search_insert_position.cpp
  > Author: lax
  > Mail: xingkungao@gmail.com
  > Created Time: Mon 15 Dec 2014 05:10:42 PM CST
 ************************************************************************/

#include "CPP.h"
#include "utility.h"
using namespace std;

class Solution {
	public:
		int searchInsert(int A[], int n, int target) {
			if (n <= 0)
				return 0;
			int l = 0, r = n - 1, mid;
			while (l < r) {
				mid = (l + r) / 2;
				if (A[mid] < target) 
					l = mid + 1;
				else 
					r = mid;
			}
			if (target > A[n-1])
				return n;
			return l;
		}
		void test() {
			int A[100];
			int n, x;
			while (1) {
				cin >> n;
				for (int i = 0; i < n; i++)
					cin >> A[i];
				while (cin >> x && x >= 0)
					cout << (searchInsert(A, n, x)) << endl; 
			}
		}
};

int main() {
	Solution s;
	s.test();
}
