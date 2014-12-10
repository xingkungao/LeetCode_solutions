/*************************************************************************
  > File Name: remove_element.cpp
  > Author: lax
  > Mail: xingkungao@gmail.com
  > Created Time: Wed 10 Dec 2014 04:47:27 PM CST
 ************************************************************************/

#include <iostream>
#include <cstdio>
using namespace std;
class Solution {
	public:
		int removeElement(int A[], int n, int elem) {
			int cnt = 0;
			int l = 0, r = n - 1;

			while (l <= r) {
				while (l < n && A[l] != elem)
					l++;
				while (r >= 0 && A[r] == elem) {
					r--;
					cnt++;
				}
				if (l < r){
					A[l] = A[r];
					l++;
					r--;
					cnt++;
				}
			}
			return n - cnt;
		}
		void test() {
			int A[100];
			int n;
			int elem;
			while (1){
				cin >> n;
				for (int i = 0;i < n; i++)
					cin >> A[i];
				cin >> elem;
				n = removeElement(A, n, elem);
				cout << "new length: " << n << endl;
				for (int i = 0; i < n; i++)
					cout << A[i] << " ";
				cout << endl;
			}
		}
};

int main() {
	Solution s;
	s.test();
}

