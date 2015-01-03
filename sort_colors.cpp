/*************************************************************************
    > File Name: sort_colors.cpp
    > Author: lax
    > Mail: xingkungao@gmail.com
    > Created Time: Sat 03 Jan 2015 08:32:23 PM CST
 ************************************************************************/

#include "CPP.h"
#include "utility.h"
using namespace std;
class Solution {
	public:
		void sortColors(int A[], int n) {
		}
		void sortColors2(int A[], int n) {
			int l = 0, r = n - 1, left = 0, right = n - 1;
			int num; 
			while (l <= r) {
				//cout << "a[" << l << "]:" << A[l] << " a[" << r << "]:" << A[r] << endl;
				if (A[l] == 0)
					swap(A[left++], A[l]);
				else if (A[l] == 1)
					l++;
				else 
					swap(A[right--], A[l]);

				l = max(l, left);
				r = min(r, right);
				if (l > r)
					break;
				if (A[r] == 0)
					swap(A[left++], A[r]);
				else if (A[r] == 1)
					r--;
				else 
					swap(A[right--], A[r]);
				l = max(l, left);
				r = min(r, right);

			}
		}
		void sortColorsStandard(int A[], int n) {
			int p = 0, i = 0, q = n - 1;
			while (i <= q) {
				if (A[i] < 1) {
					swap(A[p++], A[i++]);
				}
				else if (A[i] > 1) {
					swap(A[i], A[q--]);
				}
				else 
					i++;
			}
		}
		void test() {
			int a[100];
			int n;
			while (1) {
				cin >> n;
				for (int i = 0; i < n; i++)
					cin >> a[i];
				sortColors(a, n);
				for (int i = 0; i < n; i++)
					cout << a[i] << '\t';
				cout << endl;
			}
		}
};

int main() {
	Solution s;
	s.test();
}
