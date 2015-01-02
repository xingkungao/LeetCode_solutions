/*************************************************************************
  > File Name: jump_game.cpp
  > Author: lax
  > Mail: xingkungao@gmail.com
  > Created Time: Fri 02 Jan 2015 03:26:54 PM CST
 ************************************************************************/

#include "CPP.h"
#include "utility.h"
using namespace std;

class Solution {
	public:
		bool canJump(int A[], int n) {
			//			return canJumpDP(A, n);
			//			return canJumpMemoization(A, n);
			//return canJumpGreedy(A, n);
			return canJumpDP2(A, n);
		}
		bool canJumpGreedy(int A[], int n) {
			int m;
			int i = 0, j, k;
			if (n == 1)
				return true;
			while (i < n) {
				m = -1;
				k = i;

				for (int j = i + 1; j <= i + A[i]; j++) {
					if (j >= n - 1)
						return true;
					if (A[j] + j > m) {
						m = A[j] + j;
						k = j;
					}
				}
				if (k == i)
					return false;
				else 
					i = k;
			}
			return false;

		}
		bool canJumpDP(int A[], int n) {
			if (n <= 0)
				return false;
			bool flag[n];
			for (int i = 0; i < n; i++) 
				flag[i] = false;
			flag[0] = true;
			for (int i = 1; i < n; i++) {
				for (int j = 0; j < i; j++) {
					if (flag[j] && A[j] >= i - j) {
						flag[i] = true;
						break;
					}
				}
			}
			return flag[n-1];
		}
		bool canJumpDP2(int A[], int n) {
			if (n == 1)
				return true;
			int i;
			int m = A[0];
			for (i = 1; i < n; i++) {
				if (m == 0)
					return false;
				m = max(m - 1, A[i]);
			}
			return true;
		}
		bool canJumpMemoization(int A[], int n) {
			if (n <= 0)
				return false;
			int flag[n];
			for (int i = 0; i < n; i++) 
				flag[i] = -1;
			flag[0] = 1;
			return canJumpMemoizationRecur(A, n, flag, n-1);
		}
		bool canJumpMemoizationRecur(int *a, int n, int *flag, int idx) {
			if (idx == 0)
				return true;
			else if (flag[idx] != -1)
				return flag[idx];
			for (int i = 0; i < idx; i++)
				if (canJumpMemoizationRecur(a, n, flag, i) && a[i] >= idx - i)
					return (flag[idx] = 1);
			return (flag[idx] = 0);
		}

		void test() {
			int A[100];
			int n;
			while (1) {
				cin >> n; 
				for (int i = 0; i < n; i++)
					cin >> A[i];
				cout << boolalpha << canJump(A, n) << endl;
			}
		}
};


int main() {
	Solution s;
	s.test();
}
