/*************************************************************************
    > File Name: merge_sorted_array.cpp
    > Author: lax
    > Mail: xingkungao@gmail.com
    > Created Time: Thu 04 Dec 2014 09:47:09 PM CST
 ************************************************************************/

#include <iostream>
#include <cstdio>
using namespace std;
class Solution {
	public:
		void merge(int A[], int m, int B[], int n) {
			int C[m];
			for (int i = 0; i < m; i++) 
				C[i] = A[i];

			int len = 0;
			int i = 0, j = 0;
			while (i < m && j < n) {
				if (C[i] <= B[j]) 
					A[len++] = C[i++];
				else 
					A[len++] = B[j++];
			}
			if (i == m) 
				while (j < n)
					A[len++] = B[j++];
			else 
				while (i < m) 
					A[len++] = C[i++];
		}
		void insert(int A[], int& len, int data, int pos) {
			for (int i = len - 1; i >= pos; i--) {
				A[i+1] = A[i];
			}
			A[pos] = data;
			len++;
		}
		void test() {
	     int A[100];
		 int B[10];
		 int m, n;
		 while (1) {
			 cin >> m;
			 for (int i = 0; i < m; i++) 
				 cin >> A[i];
			 cin >> n;
			 for (int i = 0; i < n; i++) 
				 cin >> B[i];
			 merge(A, m, B, n);
			 cout << "result\n";
			 for (int i = 0; i  < m + n; i++) 
				 cout << A[i] << ' ';
			 cout << endl;
		 }

		}
};
int main() {
	Solution s;
	s.test();
}

