/*************************************************************************
    > File Name: strstr.cpp
    > Author: lax
    > Mail: xingkungao@gmail.com
    > Created Time: Tue 09 Dec 2014 12:13:40 AM CST
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
class Solution {
	public:
		int strStr(char *haystack, char *needle) {
			int n = strlen(haystack);
			int m = strlen(needle);
			if (!m)
				return 0;
			int *next = lpps(needle);
			int len = 0, i = 0;
			while (len < n) {
				if(needle[i] == haystack[len]) {
					len++;
					i++;
				}
				else {
					if (i >= 1)
						i = next[i-1];
					else { 
						len++;
					}
				}
				if (i >= m) {
					delete next;
					return len - i;
				}
			}
			delete(next);
			return -1;
		}

		int* lpps (char *p) {
			int n = strlen(p);
			int *next = new int[n]; 
			next[0] = 0;
			int len = next[0], i = 1;
			while (i < n) {
				if (p[len] == p[i]){
					len++;
					next[i] = len;
					i++;
				}
				else {
					if (len > 0) {
						len = next[len-1];
					}
					else {
						next[i] = 0; 
						i++;
					}
				}

			}
			return next;
		}
		void print(int* a, int n) {
			cout << "auxiliary next array is:\n";
			for (int i = 0; i < n; i++)
				cout << a[i] << " ";
			cout << endl;
		}
		void test() {
			char str[100];
			char pattern[30];
			while (1) {
				cin >> str;
				cin >> pattern;
				cout << strStr(str, pattern) << endl; 
				int index = (long)((void*)(strstr(str, pattern)- (&str[0]))); 
				cout << index << endl;
			}
		}
};
int main() {
	Solution s;
	s.test();
}
