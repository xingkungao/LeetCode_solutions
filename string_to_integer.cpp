/*************************************************************************
    > File Name: string_to_integer.cpp
    > Author: lax
    > Mail: xingkungao@gmail.com
    > Created Time: Sat 27 Dec 2014 12:58:43 AM CST
 ************************************************************************/

#include "CPP.h"
#include "utility.h"
using namespace std;
class Solution {
	public:
		int atoi(const char *str) {
			int ret = 0;
			bool negative = false;
			bool overflow = false;

			int cutoff = INT_MAX / 10;
			int cutlim = INT_MAX % 10;
			char c;
			if (!str) 
				return ret;

			while (isspace(*str)) 
				++str;

			if (*str == '-') {
				negative = true;
				++str;
			}
			else if (*str == '+') {
				++str;
			}
			
			for (c = *str; c!= '\0'; c = *++str) {
				if (!isdigit (c))
					break;
					c -= '0';
					if (ret > cutoff || ret == cutoff && c > (negative ? cutlim + 1 : cutlim)) {
						overflow = true;
						break;
					}
					else 
						ret = ret * 10 + c;
			}
			if (overflow)
				return (negative ? INT_MIN : INT_MAX);

			return (negative ? -ret : ret);
		}

		void test() {
			string s;
			while (1) {
				cin >> s;
				cout << atoi(s.c_str()) << endl;
			}
		}
};

int main() {
	Solution s;
	s.test();
}
