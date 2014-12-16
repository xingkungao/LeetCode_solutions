/*************************************************************************
  > File Name: count_and_say.cpp
  > Author: lax
  > Mail: xingkungao@gmail.com
  > Created Time: Tue 16 Dec 2014 08:45:44 PM CST
 ************************************************************************/

#include "CPP.h"
#include "utility.h"
class Solution {
	public:
		string countAndSay(int n) {
			char buf[500];
			string a = "1", b;
			int k;
			unsigned long long c;
			char d;
			if (n == 1)
				return a;
			for (int i = 2; i <= n; i++) {
				c = 1; 
				d = a[0]; 
				b.clear();
				for (int j = 1; j < a.length(); j++) {
					if (a[j] != a[j-1]) {
						tostring(buf, c);
						b.append(buf);
						/*
						k = 0;
						while (buf[k]) {
							b.push_back(buf[k++]);
						}
						*/
						b.push_back(d);
						c = 1;
						d = a[j];
					}
					else {
						c++;
					}
				}
						tostring(buf, c);
						b.append(buf);
//				b.push_back(c);
				b.push_back(d);
				a = b;
			}
			return a;

		}
		void test() {
			int n;
			char a[100];
			while (1) {
				cin >> n;
				cout << countAndSay(n) << endl;
			}
		}
		void tostring(char str[], unsigned long long num) {
			int i, rem, len = 0;
			unsigned long long n;
			n = num;


			do {

				len++;

				n /= 10;

			}while (n);

			for (i = 0; i < len; i++)

			{

				rem = num % 10;

				num = num / 10;

				str[len - (i + 1)] = rem + '0';

			}

			str[len] = 0;

		}
};

int main() {
	Solution s;
	s.test();
}
