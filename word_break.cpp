/*************************************************************************
    > File Name: word_break.cpp
    > Author: lax
    > Mail: xingkungao@gmail.com
    > Created Time: Wed 03 Dec 2014 02:32:04 PM CST
 ************************************************************************/

#include <iostream>
#include <string>
#include <cstdio>
#include <unordered_set>
using namespace std;
class Solution {
	public:
		bool wordBreak(string s, unordered_set<string> &dict) {
			int len = s.length();
			bool f[len];
			for (int i = 0; i < len; i++)
				f[i] = 0;
			for (int i = 0; i < len; i++) 
				for (int j = i; j >= 0; j--) {
					f[i] |= dict.find(s.substr(j, i - j + 1)) != dict.end() && (!j ? true : f[j-1]);
				}
				return f[len-1]; 
		}
};
int main() {
	Solution s;
	string str = "leetcode";
	unordered_set<string> set = {"l", "e", "t", "code"};
	cout << boolalpha << s.wordBreak(str, set);
}
