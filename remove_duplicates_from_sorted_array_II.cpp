/*************************************************************************
  > File Name: remove_duplicates_from_sorted_array_II.cpp
  > Author: lax
  > Mail: xingkungao@gmail.com
  > Created Time: Sun 04 Jan 2015 01:31:51 PM CST
 ************************************************************************/

#include "CPP.h"
#include "utility.h"
using namespace std;

class Solution {
	public:
		int removeDuplicates(int A[], int n) {
			int l = 0;
			for (int i = 0; i < n; i++) {
				if (l >= 2 && A[i] == A[l-1] && A[i] == A[l-2])
					continue;
				else {
					A[l++] = A[i];

//					swap(A[l++], A[i]);
				}
			}
			return l;
		}
		void test() {
			int A[100];
			int n;
			while (1) {
				cin >> n;
				for (int i = 0; i < n; i++) 
					cin >> A[i];
				n = removeDuplicates(A, n);
				cout << "length: " << n << endl;
				for (int i = 0; i < n; i++) 
					cout << A[i] << '\t';
				cout << endl;
			}
		}
};

int main() {
	Solution s;
	s.test();
}
