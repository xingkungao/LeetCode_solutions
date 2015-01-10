/*************************************************************************
  > File Name: fraction_to_recurring_decimal.cpp
  > Author: lax
  > Mail: xingkungao@gmail.com
  > Created Time: Thu 08 Jan 2015 02:05:49 PM CST
 ************************************************************************/

#include "CPP.h"
#include "utility.h"
using namespace std;

class Solution {
	public:
		/*
		string fractionToDecimal(int numerator, int denominator) {
			long long a = numerator, b = denominator;
			int cnt = 0;
			if (a < 0) {
				cnt++;
				a = -a;
			}
			if (b < 0) {
				cnt++;
				b = -b;
			}
			int num2 = 0, num5 = 0;
			int n = 0, m = 0;
			while (b % 2 == 0)  {
				b = (b >> 1);
				cout << "/2\n";
				num2++; } while (b % 5 == 0)  {
				b /= 5;
				cout << "/2\n";
				num5++;
			}
			n = max(num2, num5);
			if(b != 1) {
				m = 1;
				long long  tmp = 10;
				while ((tmp-1)%b != 0) {
					tmp *= 10;
					cout << "fuck\n";
					m++;
				}
			}

			ostringstream convert;
			convert << (a / denominator);
			string ret;
			if (cnt&1)
				ret.push_back('-');
			ret.append(convert.str());

			if (n || m) {
				ret.push_back('.');
				if (n) {
					for (int i = 0; i < n; i++)
						a *= 10;
					ostringstream convert;
					convert << (a / denominator);
					string tmp = convert.str();

					if (tmp.length() < n) 
						tmp.insert(tmp.begin(), n-tmp.length(), '0');
					ret.append(tmp.substr(tmp.length() - n, n));
				}

				if (m) {
					for (int i = 0; i < m; i++)
						a *= 10;
					ostringstream convert;
					convert << (a / denominator);
					string tmp = convert.str();
					ret.push_back('(');
					if (tmp.length() < m) 
						tmp.insert(tmp.begin(), m-tmp.length(), '0');
					ret.append(tmp.substr(tmp.length() - m, m));
					ret.push_back(')');
				}

			}
			return ret;
		}
		*/
		string fractionToDecimal(int numerator, int denominator) {
			long long a = numerator, b = denominator;
			string ret;
			if (!a)
				return string("0");
			if (!b)
				return ret;
			if (a < 0 ^ b < 0)
				ret.push_back('-');
			a = abs(a);
			b = abs(b);
			ret += to_string(a/b);
			if (a%b) {
				ret.push_back('.');
				unordered_map<int, int> dict;
				long long r = a % b;
				while (r) {
					if (dict.find(r) != dict.end()) {
						ret.insert(dict[r], 1, '(');
						ret.push_back(')');
						break;
					}
					dict[r] = ret.length();
					r *= 10;
					ret += to_string(r / b);
					r = r % b;
				}
			}
			return ret;
		}
		void test() {
			int a, b;
			while (1) {
				cin >> a >> b;
				cout << fractionToDecimal(a, b) << endl;
			}
		}
};
int main() {
	Solution s;
	s.test();
}
