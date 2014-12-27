/*************************************************************************
  > File Name: longest_valid_parentheses.cpp
  > Author: lax
  > Mail: xingkungao@gmail.com
  > Created Time: Wed 10 Dec 2014 07:50:55 PM CST
 ************************************************************************/

#include "CPP.h"
#include "utility.h"
using namespace std;
class Solution {
	public:
		int longestValidParentheses(string s) {
			vector<int> ret(s.size());
			int idx;
			int m = 0;
			for (int i = 0; i < s.length(); i++) {
				ret[i] = 0;
				if (s[i] == ')' && i) {
					idx = i - 2 * ret[i-1] - 1;
					if (idx >= 0 && s[idx] == '(') {
						ret[i] = 1 + ret[i-1];
						if (idx -1 >= 0)
							ret[i] += ret[idx-1];
					}
				}
				m = max(m, ret[i]);
			}
			return m * 2;
		}
		void test() {
			string s;
			while (1) {
				cin >> s;
				cout << longestValidParentheses(s) << endl;
			}
		}
};

int main() {
	Solution s;
	s.test();
}
