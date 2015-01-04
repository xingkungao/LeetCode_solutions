/*************************************************************************
  > File Name: compare_version_number.cpp
  > Author: lax
  > Mail: xingkungao@gmail.com
  > Created Time: Sun 04 Jan 2015 06:05:32 PM CST
 ************************************************************************/

#include "CPP.h"
#include "utility.h"
using namespace std;
class Solution {
	public:
		int compareVersion(string version1, string version2) {
			int p1 = -1, p2 = 0, q1 = -1, q2 = 0;
			int d, a , b;
			string t1, t2;

			while (p2 < version1.length() && q2 < version2.length()) {
				p1 = p1 < 0 ? 0 : p2;
				while (version1[p2] != '.' && p2 < version1.length())
					p2++;

				q1 = q1 < 0 ? 0 :  q2;
				while (version2[q2] != '.' && q2 < version2.length())
					q2++;
				//				cout << "(" << p1 << "," << p2 << "):" << version1.substr(p1, p2 - p1) << "    " << "(" << q1 << "," << q2 << "):" <<  version2.substr(q1, q2-q1); 
				a = atoi(version1.substr(p1, p2-p1).c_str());
				b = atoi(version2.substr(q1, q2-q1).c_str());

				d = a - b;
//				cout << "   " <<  a << b << endl;
				if (d == 0) {
					if (p2 < version1.length()) p2 ++;
					if (q2 < version2.length()) q2 ++;
				}
				else if (d < 0) {
					return -1;
				}
				else {
					return 1;
				}

			}

			int i;
			if (p2 == version1.length() && q2 == version2.length())
				return 0;

			else if (p2 == version1.length()) {
				//				cout << version2.substr(q2, version2.length() - q2) << endl;
				while (q2 < version2.length()) {
					q1 = q2;
					while (version2[q2] != '.' && q2 < version2.length())
						q2++;
					b = atoi(version2.substr(q1, q2-q1).c_str());
					if (b != 0)
						return -1;
					q2++;
				}
				return 0;
			}
			else {
				while (p2 < version1.length()) { 
					p1 = p2;
					while (version1[p2] != '.' && p2 < version1.length())
						p2++;
					a = atoi(version1.substr(p1, p2-p1).c_str());
					if (a != 0)
						return 1;
					p2++;
				}
				return 0;

			}
		}

		void test() {
			string a, b;
			a = "19.8.3.17.5.01.0.0.4.0.0.0.0.0.0.0.0.0.0.0.0.0.00.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.000000.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.000000";
			b = "19.8.3.17.5.01.0.0.4.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0000.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.000000";
			cout << compareVersion(a, b) << endl;
			while (1) {
				cin >> a >> b;
				cout << compareVersion(a, b) << endl;
			}
		}
};

int main() {
	Solution s;
	s.test();
}
