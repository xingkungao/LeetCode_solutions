/*************************************************************************
    > File Name: excel_sheet_column_number.cpp
    > Author: lax
    > Mail: xingkungao@gmail.com
    > Created Time: Sun 28 Dec 2014 05:01:55 PM CST
 ************************************************************************/

#include "CPP.h"
#include "utility.h"
using namespace std;

class Solution {
	public:
		int titleToNumber(string s) {
			int ret = 0;
			int d;
			for (int i = 0; i < s.length(); i++)  {
				d = s[i] - 'A' + 1;
				ret = ret * 26 + d;
			}
			return ret;

		}
		void test() {
			string s;
			while (1) {
				cin >> s;
				for (int i = 0; i < s.length(); i++)
					s[i] = toupper(s[i]);
				cout << titleToNumber(s) << endl;
			}
		}
};

int main() {
	Solution s;
	s.test();
}
