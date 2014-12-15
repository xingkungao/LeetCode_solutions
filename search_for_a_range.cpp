/*************************************************************************
  > File Name: search_for_a_range.cpp
  > Author: lax
  > Mail: xingkungao@gmail.com
  > Created Time: Mon 15 Dec 2014 04:11:47 PM CST
 ************************************************************************/

#include "CPP.h"
#include "utility.h"
using namespace std;
class Solution {
	public:
		vector<int> searchRange(int A[], int n, int target) {
			vector<int> v(2, -1);
			if (n <= 0)
				return v;

			int l = 0, r = n - 1;
			while (l < r) {
				int mid = (l + r) / 2;
				if (A[mid] < target) {
					l = mid + 1;
				}
				else {
					r = mid;
				}
			}
			if (A[l] == target)
				v[0] = l;
			else 
				return v;

			r = n - 1;
			while (l < r) {
				int mid = (l + r) / 2 + 1;
				if (A[mid] <= target) {
					l = mid;
				}
				else {
					r = mid - 1;
				}
			}
			if (A[l] == target)
				v[1] = l;
			return v;  
		}
		void test() {
			int A[100];
			int n, x;
			while (1) {
				cin >> n;
				for (int i = 0; i < n; i++)
					cin >> A[i];
				while (cin >> x && x > 0)
					print1DVector(searchRange(A, n, x)); 
			}
		}
};

int main() {
	Solution s;
	s.test();
}
