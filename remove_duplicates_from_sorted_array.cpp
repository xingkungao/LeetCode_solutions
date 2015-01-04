/*************************************************************************
    > File Name: remove_duplicates_from_sorted_array.cpp
    > Author: lax
    > Mail: xingkungao@gmail.com
    > Created Time: Wed 10 Dec 2014 05:25:39 PM CST
 ************************************************************************/

#include <iostream>
#include <cstdio>
using namespace std;
class Solution {
	public:
		int removeDuplicates(int A[], int n) {
			if (!n)
				return 0;
			int l = 0;
			for (int i = 1; i < n; i++) {
				if (A[l] != A[i]) {
					l++;
					A[l] = A[i];
				}
			}
			return l+1;
		}
		void test() {
			int a[100];
			int n; 
			while (1) {
				cin >> n;
				for (int i = 0; i < n; i++)
					cin >> a[i];
				int len =  removeDuplicates(a, n);
				cout << "new array:" << endl;
				for (int i = 0; i < len; i++)
					cout << a[i] << " ";
				cout << endl;
			}
		}
};


int main() {
	Solution s;
	s.test();
}
