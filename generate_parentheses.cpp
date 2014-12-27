/*************************************************************************
  > File Name: generate_parentheses.cpp
  > Author: lax
  > Mail: xingkungao@gmail.com
  > Created Time: Tue 16 Dec 2014 09:46:01 PM CST
 ************************************************************************/

#include "CPP.h"
#include "utility.h"
using namespace std;

class Solution {
	public:
		vector<string> generateParenthesis(int n) {
			/*
			vector<string> ret;
			if (n <= 0)
				return ret;
			string s(2*n,'(');
			generateParenthesisBacktracking(ret, s, 0, n, n, 0);
			return ret;
			*/
			return generateParenthesisDP(n); 
		}

		void generateParenthesisBacktracking(vector<string> &v, string &s, int pos, int nl, int nr, int sum) {
			if ((nl >= 0 || nr >= 0) && sum >= 0 ) {
				if (pos == s.length() && sum == 0) {
					v.push_back(s);
					return;
				}
				if (nl > 0 && sum + 1 > 0) {
					s[pos] = '(';
					generateParenthesisBacktracking(v, s, pos + 1, nl - 1, nr, sum+1);
				}
				if (nr > 0 && sum - 1 >= 0)  {
					s[pos] = ')';
					generateParenthesisBacktracking(v, s, pos + 1, nl, nr - 1, sum-1);
				}
			}
		}

		vector<string> generateParenthesisDP(int n) {
			vector<vector<string>> ret;
			ret.push_back(vector<string>(1, ""));
			for (int i = 1; i <= n; i++) {
				vector<string> v;
				for (int j = 0; j < i; j++) {
					// f[j] f[i-1-j]
					for (auto  e : ret[j]) {
						for (auto f : ret[i-1-j]) {
							string a;
							a.append("(");
							a.append(e);
							a.append(")");
							a.append(f);
							v.push_back(a);
						}
					}

				}
				ret.push_back(v);

			}
			return ret[n];
		}

		void test() {
			int n;
			vector<string> v;
			while (1) {
				cin >> n;
				print1DVector(generateParenthesis(n));
			}
		}
};

int main() {
	Solution s;
	s.test();
}
