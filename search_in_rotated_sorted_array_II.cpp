/*************************************************************************
  > File Name: search_in_rotated_sorted_array_II.cpp
  > Author: lax
  > Mail: xingkungao@gmail.com
  > Created Time: Sun 04 Jan 2015 01:54:49 PM CST
 ************************************************************************/

#include "CPP.h"
#include "utility.h"
using namespace std;

class Solution {
	public:
		bool search(int A[], int n, int target) {
			int l = 0, r = n - 1, mid;
			if (n == 0)
				return false;
			bool left = true;
			int guard = A[0];
			if (target < guard)
				left = false;
			while (l <= r) {
				mid = (l + r) / 2;
				if (A[mid] == target)
					return true;
				else if (A[mid] > target) {

					if (A[mid] >= guard) {
						if (left)
							r = mid - 1;
						else 
							l = mid + 1;
					}
					else { 
						r = mid - 1;
					}
				}
				else {
					if (A[mid] >= guard) {
						l = mid + 1;
					}
					else {
						if (left) 
							r = mid - 1;
						else 
							l = mid + 1;
					}
				}
			}
			if (A[0] == A[n-1])
				for (int i = 0; i < n; i++)
					if (A[i] == target)
						return true;
			return false;
		}
		void test() {
			int A[100];
			int n, x;
			while (1) {
				cin >> n;
				for (int i = 0; i < n; i++)
					cin >> A[i];
				while (cin >> x && x != -1000)
					cout << boolalpha << search(A, n, x) << endl;
			}
		}
};

int main() {
	Solution s;
	s.test();
}
