/*************************************************************************
  > File Name: permutation_sequence.cpp
  > Author: lax
  > Mail: xingkungao@gmail.com
  > Created Time: Fri 26 Dec 2014 08:49:04 PM CST
 ************************************************************************/

#include "CPP.h"
#include "utility.h"
using namespace std;

class Solution {
	public:
		string getPermutation(int n, int k) {
			int factorial[10] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
			vector<bool> flag(10, false);
			k--;
			string ret;
			if (n == 1) {
				ret.push_back(n + '0');
				return ret;
			}
			int d, r, idx;
			for (int i = 1; i <= n; i++) {
				d = k / factorial[n-i] + 1;
				k = k % factorial[n-i];
				int cnt = 0;
				for (int j = 1; j <= n; j++) 
					if(!flag[j]) {
						cnt++;
						if (cnt == d)  {
							ret.push_back(j + '0');
							flag[j] = true;
						}
					}
			}
			return ret;

		}
		void test() {
			int n, k;
			while (1) {
				cin >> n;
				cin >> k;
				cout << getPermutation(n, k) << endl;
			}
		}
};

int main() {
	Solution s;
	s.test();
}

