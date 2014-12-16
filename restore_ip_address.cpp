/*************************************************************************
  > File Name: restore_ip_address.cpp
  > Author: lax
  > Mail: xingkungao@gmail.com
  > Created Time: Tue 16 Dec 2014 01:44:48 PM CST
 ************************************************************************/

#include "CPP.h"
#include "utility.h"
using namespace std;

class Solution {
	public:
		vector<string> restoreIpAddresses(string s) {
			int len = s.length();
			int bar[4];
			for (int i = 0; i < 4; i++)
				bar[i] = -1;
			vector<string> v;
			restoreIpAddressesRecursive(v, s, bar, len, 0, 0); 
			return v;

		}
		void restoreIpAddressesRecursive(vector<string> &v, string &s, int *bar, int len, int pos, int spe) {
			if (spe == 4) {
				if (pos == len) {
					string line;
					int cnt = 0;
					for (int i = 0; i < len; i++) {
						line.push_back(s[i]);
						if (i == bar[cnt]) {
							line.push_back('.');
							cnt++;
						}
					}
					line.pop_back();
					v.push_back(line); 
				}
				return;
			}

			for (int i = pos; i < len; i++)  {
				if ((len - 1 - i) / (4 - spe) <= 3 ) {
					int start = spe == 0 ? 0 : bar[spe-1] + 1;
					if (isValid(s.substr(start, i - start + 1))) {
						bar[spe] = i;
						restoreIpAddressesRecursive(v, s, bar, len, i + 1, spe + 1); 
						bar[spe] = -1;
					}
				}
			}

		}
		bool isValid(string s) {
			int i = 0;
			while (i < s.length() && s[i] == '0')
				i++;
			return (!i  || i == 1 && s.length() == 1) && atoi(s.c_str()) <= 255;
		}
		void test() {
			string s;
			while (cin >> s) {
				vector<string> a = restoreIpAddresses(s);
				cout << "size: " << a.size() << endl;
				print1DVector<string>(a);
				cout << endl;
			}
		}
};

int main() {
	Solution s;
	s.test();
}
