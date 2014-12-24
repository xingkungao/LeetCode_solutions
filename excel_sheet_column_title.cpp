/*************************************************************************
    > File Name: excel_sheet_column_title.cpp
    > Author: lax
    > Mail: xingkungao@gmail.com
    > Created Time: Wed 24 Dec 2014 09:52:27 PM CST
 ************************************************************************/

#include "CPP.h"
#include "utility.h"
using namespace std;

class Solution {
	public:
		string convertToTitle(int n) {
		long long d = n;
			string v;
			if (n <= 0)
				return v;
			int r;
			while (d) {
				v.push_back( (25 + d) % 26 + 'A');
				d = (d-1) / 26;
			}
			reverse(v.begin(), v.end());
			return v;
		}
		void test() {
			int n; 
			while (1) {
				cin >> n;
				cout << convertToTitle(n) << endl;
			}
		}
};

int main() {
	Solution s;
	s.test();
}
		
