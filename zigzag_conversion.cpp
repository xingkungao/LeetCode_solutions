/*************************************************************************
  > File Name: zigzag_conversion.cpp
  > Author: lax
  > Mail: xingkungao@gmail.com
  > Created Time: Sun 07 Dec 2014 02:18:48 PM CST
 ************************************************************************/

#include <iostream>
#include <cstdio>
using namespace std;
class Solution {
	public:
		string convert(string s, int nRows) {
			string r;
			int len = s.length();
			int interval  = 2 * nRows - 2;
			if (interval == 0)
				return s;
			int idx;
			for (int i = 0; i < nRows; i++) {
				idx = i;
				while (idx < len)  {
					r += (s[idx]);
					int idx2 = idx + interval - 2 * i;
					if (idx2 < len && idx2 < idx + interval && idx2 != idx) {
						r += (s[idx2]);
					}
					idx += interval;
				}
			}
			return r;
		}
		void test() {
			string s;
			int r;
			while (1) {
				cin >> s;
				cin >> r;
				cout << convert(s, r) << endl;
			}
		}
};
int main() {
	Solution s;
	s.test();
}
