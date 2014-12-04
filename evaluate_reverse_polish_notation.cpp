/*************************************************************************
    > File Name: evaluate_reverse_polish_notation.cpp
    > Author: lax
    > Mail: xingkungao@gmail.com
    > Created Time: Thu 17 Apr 2014 04:39:37 PM CST
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <stack>
#include <cstring>
using namespace std;
class Solution {
	public:
		int evalRPN(vector<string> &tokens) {
			int len = tokens.size();
			int op1, op2;
			stack<int> s;
			for (int i = 0; i < len; i++) {
				if (tokens[i] == "+" || tokens[i] == "-" \
						|| tokens[i] == "*" || tokens[i] == "/"){
					op2 = s.top();
					s.pop();
					op1 = s.top();
					s.pop();
					if (tokens[i] == "+")
						s.push(op1 + op2);
					else if (tokens[i] == "-")
						s.push(op1 - op2);
					else if (tokens[i] == "*")
						s.push(op1 * op2);
					else if (tokens[i] == "/")
						s.push(op1 / op2);
				}
				else {
					s.push(atoi(tokens[i].c_str()));
				}
			}
			return s.top();
		}
};
int main() {
	Solution s;
	vector<string> v;
	v.push_back("2");
	v.push_back("1");
	v.push_back("+");
	v.push_back("3");
	v.push_back("*");
	cout << s.evalRPN(v);

}




