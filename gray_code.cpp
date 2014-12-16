/*************************************************************************
    > File Name: gray_code.cpp
    > Author: lax
    > Mail: xingkungao@gmail.com
    > Created Time: Tue 16 Dec 2014 03:38:14 PM CST
 ************************************************************************/

#include "CPP.h"
#include "utility.h"
using namespace std;

class Solution {
	public:
		vector<int> grayCode(int n) {
			vector<int> ret;
			ret.push_back(0);
			if (n <= 0)
				return ret;
			ret.push_back(1);
			for (int i = 2; i <= n; i++) {
				for (long long j = ret.size() - 1; j >= 0; j--) {
					ret.push_back(ret[j] + (1 << (i - 1)));
				}
			}
			return ret;
		}
		void test() {
			int n;
			while (1) {
				cin >> n; 
				print1DVector(grayCode(n));
			}
		}
};

int main() {
	Solution s;
	s.test();
}
