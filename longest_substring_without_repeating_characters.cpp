/*************************************************************************
    > File Name: longest_substring_without_repeating_characters.cpp
    > Author: lax
    > Mail: xingkungao@gmail.com
    > Created Time: Thu 04 Dec 2014 04:53:33 PM CST
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <string>
#include <cstdio>
using namespace std;
class Solution {
	public:
		int lengthOfLongestSubstring(string s) {
			int len = s.length();
			int result = 0, m = 0;
			size_t pos;
			for (int i = 0; i < len; i++) {
				if (!i) 
					m = 1;
				else if ((pos = s.substr(i-m, m).find(s[i])) != string::npos) {
					m -= pos;
				}
				else 
					m++;
				result = std::max(result, m);
			}
			return result;
		}
		void test() {
			while (1) {
			string s;
			cin >> s;
			cout << lengthOfLongestSubstring(s);
			cout << endl;
			}
		}
};
int main() {
	Solution s;
	s.test();
}
