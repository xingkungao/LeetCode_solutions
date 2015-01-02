/*************************************************************************
  > File Name: jump_game_II.cpp
  > Author: lax
  > Mail: xingkungao@gmail.com
  > Created Time: Fri 02 Jan 2015 08:01:34 PM CST
 ************************************************************************/

#include "CPP.h"
#include "utility.h"
using namespace std;

class Solution {
	public:
		int jump(int A[], int n) {
			return jumpGreedy(A, n);
		}
		int jumpGreedy(int A[], int n) {
			int cnt = 0;
			if (n == 1)
				return cnt;
			int i = 0;
			int m = -1, idx;
			while (i < n) {
				for (int j = i + 1; j <= A[i] + i; j++) {
					if (j == n - 1)
						return cnt + 1;
					if (m < A[j] + j) {
						m = A[j] + j;
						idx = j;
					}
				}
				i = idx;
				cnt ++;
			}
			return cnt;
		}
		int jumpGreedy2(int A[], int n) {
			int ret = 0;
			int last = 0, cur = 0;
			for (int i = 0; i < n; i++) {
				if (i > last) {
					if (last == cur)
						return -1;
					last = cur;
					ret++;
				}
				cur = max(cur, i + A[i]);
			}
			return ret;
		}
		void test() {
			int A[100];
			int n;
			while (1) {
				cin >> n;
				for (int i = 0; i < n; i++)
					cin >> A[i];
				cout << jump(A, n) << endl;
			}
		}

};

int main() {
	Solution s;
	s.test();
}
