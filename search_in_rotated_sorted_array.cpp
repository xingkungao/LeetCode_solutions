/*************************************************************************
  > File Name: search_in_rotated_sorted_array.cpp
  > Author: lax
  > Mail: xingkungao@gmail.com
  > Created Time: Mon 15 Dec 2014 03:33:59 PM CST
 ************************************************************************/

#include "CPP.h"
#include "utility.h"
using namespace std;
class Solution {
	public:
		int search(int A[], int n, int target) {
			int l, r, mid, flag;
			if (n <= 0)
				return -1;
			int guard = A[0];
			if (target >= guard)
				flag = 0;
			else 
				flag = 1;
			l = 0;
			r = n - 1;
			mid = -1;
			while (l <= r) {
				mid = (l + r) / 2;
				if (A[mid] == target)
					return mid;
				else if (A[mid] > target) {
					if (A[mid] >= guard)  {
						//mid is on the left;
						if (!flag)
							// target is on the left 
							r = mid - 1;
						else
							l = mid + 1;
					}
					else {
						//mid is on the right;
//						if (flag)
							// target is on the left 
							r = mid - 1;
					}
				}
				else {
					if (A[mid] >= guard)  {
						//mid is on the left;
//						if (!flag)
							// target is on the left 
							l = mid + 1;
					}
					else {
						//mid is on the right;left
						if (!flag)
							// target is on the left 
							r = mid - 1;
						else 
							l = mid + 1;
					}
				}
			}
			return -1;
		}
		void test() {
			int A[100];
			int n, x;
			while (1) {
				cin >> n;
				for (int i = 0; i < n; i++)
					cin >> A[i];
				while (cin >> x && x != -1000)
					cout << search(A, n, x) << endl;
			}
		}
};

int main() {
	Solution s;
	s.test();
}
