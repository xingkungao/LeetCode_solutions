/*************************************************************************
  > File Name: integer_to_roman.cpp
  > Author: lax
  > Mail: xingkungao@gmail.com
  > Created Time: Sun 07 Dec 2014 03:35:14 PM CST
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <stack>
#include <vector>
#include <string>
using namespace std;
class Solution {
	public:
		string intToRoman(int num) {
			int i = 0;
			stack<string> s;
			vector<string> v;
			string token;
			char a, b, c;
			int d;
			char digits[] = "IVXLCDM";
			for (int i = 0; i < 7; i++) {
				token = string(1, digits[i]);
				v.push_back(token);
			}
			while(num) {
				token.clear();
				d = num % 10;
				num /= 10;
				if (i == 3) {
					for (int k = 0; k < d; k++)
						s.push(v[6]);
					break;
				}
				if (d == 9)
					s.push(v[2*i] + v[2*i+2]);
				else if (d >= 5) { 
					token += v[2*i+1];
					for (int k = 0; k < d - 5; k++)
						token += v[2*i];
					s.push(token);
				}
				else if (d == 4) {
					s.push(v[2*i] + v[2*i+1]);
				}
				else {
					for (int k = 0; k < d; k++)
						token += v[2*i];
					s.push(token);

				}
				i++;
			}
			string result;
			while (!s.empty()) {
				result += s.top();
				s.pop();
			}
			return result;

		}
		void test() {
			int x; 
			while (1)  {
				cin >> x;
				cout << intToRoman(x) << endl;
			}
		}

};
int main() {
	Solution s;
	s.test();
}
