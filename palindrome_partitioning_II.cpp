/*************************************************************************
  > File Name: palindrome_partitioning_II.cpp
  > Author: lax
  > Mail: xingkungao@gmail.com
  > Created Time: Tue 06 Jan 2015 07:55:53 PM CST
 ************************************************************************/

#include "CPP.h"
#include "utility.h"
using namespace std;
class Solution {
	public:
		int minCut(string s) {
			int len = s.length();
			if (!len)
				return 0;
			bool flag[len][len];
			int ret[len + 1];
			ret[0] = 0;
			for (int i = 0; i < len; i++) {
				ret[i+1] = i + 1;
				for (int j = i; j >= 0; j--) {
					flag[j][i] = (s[j] == s[i]);
					if (j + 1 <= i - 1) 
						flag[j][i] = flag[j][i] && flag[j+1][i-1];
					if (flag[j][i]) 
						ret[i+1] = min(ret[i+1], ret[j] + 1);
				}
			}
			return ret[len] - 1;
		}
		int minCut2(string s) {
			int len = s.length();
			int cut[len+1];
			for (int i = 0; i < len + 1; i++)
				cut[i] = i - 1;

			for (int i = 0;  i < len; i++) {
				/* odd length */
				for (int j = 0; i - j >= 0 && i + j < len && s[i-j] == s[i+j]; j++)
					cut[i+j+1] = min(cut[i+j+1], 1 + cut[i-j]);

				/* even length */
				for (int j = 0; i - 1 - j >= 0 && i + j < len && s[i-1-j] == s[i+j]; j++)
					cut[i+j+1] = min(cut[i+j+1], 1 + cut[i-j-1]);
			}
			return cut[len];
		}

		void test() {
			string s;
			while (1) {
				cin >> s;
				cout << minCut2(s) << endl;
			}
		}
};

int main() {
	Solution s;
	s.test();
}
