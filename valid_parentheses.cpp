/*************************************************************************
  > File Name: valid_parenthesess.cpp
  > Author: lax
  > Mail: xingkungao@gmail.com
  > Created Time: Tue 09 Dec 2014 12:18:21 AM CST
 ************************************************************************/

#include <iostream>
#include <stack>
#include <cstdio>
using namespace std;
class Solution {
	public:
		bool isValid(string s) {
			int len  = s.length();
			stack<char> ss;

			for (int i = 0; i < len; i++) {
				switch(s[i]) {
					case '(':
					case '[':
					case '{':
						ss.push(s[i]);
						break;
					case ')':
						if (ss.empty() || ss.top() == '[' || ss.top() == '{')
							return false;
						else if (ss.top() == '(')
							ss.pop();
						break;
					case ']':
						if (ss.empty() || ss.top() == '(' || ss.top() == '{')
							return false;
						else if (ss.top() == '[')
							ss.pop();
						break;
					case '}':
						if (ss.empty() || ss.top() == '(' || ss.top() == '[')
							return false;
						else if (ss.top() == '{')
							ss.pop();
				}
			}
			return ss.empty();
		}
		void test() {
			string s;
			while (1) {
				cin >> s;
				cout << boolalpha << isValid(s) << endl;
			}
		}
};

int main() {
	Solution s;
	s.test();
}
