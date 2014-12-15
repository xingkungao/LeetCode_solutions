/*************************************************************************
  > File Name: next_permutation.cpp
  > Author: lax
  > Mail: xingkungao@gmail.com
  > Created Time: Mon 15 Dec 2014 01:56:02 PM CST
 ************************************************************************/

#include "CPP.h"
#include "utility.h"
using namespace std;
class Solution {
	public:
		void nextPermutation (vector<int> &num) {
			int len = num.size();
			if (!len)
				return;
			int i = len-1, j = len -1;
			while (i > 0 && num[i] <= num[i-1])
				i--;
			if (!i) {
				std::sort(num.begin(), num.end());
			}
			else {
				i--;
				while (j > i && num[j] <= num[i])
					j--;
				swap(num[i],num[j]);
				std::reverse(num.begin() + i + 1, num.end());
			}
		}
		void test() {
			int n;
			vector<int> v;
			int x;
			while (1) {
				cin >> n; 
				for (int i = 0; i < n; i++) {
					cin >> x;
					v.push_back(x);
				}
				for (int i = 0; i <= 24; i++) {
					nextPermutation(v);
					print1DVector(v);
				}
				v.clear();

			}
		}
};
int main() {
	Solution s;
	s.test();
}
