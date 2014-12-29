/*************************************************************************
  > File Name: valid_number.cpp
  > Author: lax
  > Mail: xingkungao@gmail.com
  > Created Time: Mon 29 Dec 2014 05:05:40 PM CST
 ************************************************************************/

#include "CPP.h"
#include "utility.h"
using namespace std;

class Solution {
	public:
		bool isNumber(const char *s) {
			/*
			double d = 2.4e2l;
			cout << d << endl;
			*/
			int state = 0;
			while (*s == ' ')
				s++;
			for (s; *s != '\0'; ++s) {
				if (*s >= '0' && *s <= '9') {
					if (state == 0 || state == 1 || state == 3)
						state = 3;
					else if (state == 4 || state == 2 || state == 5)
						state = 4;
					else if (state == 8 || state == 7 || state == 9)
						state = 9;
					else 
						return false;
				}
				else if (*s == '.') {
					if (state == 0 || state == 1)
						state = 2;
					else if (state == 3)
						state = 4;
					else 
						return false;
				}
				else if (*s == 'e') {
					if (state == 3 || state == 4)
						state = 7;
					else 
						return false;
				}
				else if (*s == '+' || *s == '-') {
					if (state == 0)
						state = 1;
					else if(state == 7)
						state = 8;
					else 
						return false;

				}
				else if (*s == 'L' || *s == 'l')  {
					if (state == 3 || state == 9)
						state == 6;
					else 
						return false;
				}
				else if (*s == 'f' || *s == 'F')  {
					if (state == 9 || state == 4)
						state = 10;
					else 
						return false;
				}
				else if (*s == ' ') {
					if (state == 3 || state == 4 || state == 5 || state == 6 || state == 9 || state == 10 || state == 11)
						state = 11;
					else 
						return false;
				}
				else {
					return false;
				}
			}
			return (state == 3 || state == 4 || state == 5 || state == 6 || state == 9 || state == 10 || state == 11);
		}
		void test() {
			string s;
			while (1) {
				getline(cin, s);
				cout << boolalpha << isNumber(s.c_str()) << endl;
			}
		}
};

int main() {
	Solution s;
	s.test();
}
