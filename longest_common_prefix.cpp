/*************************************************************************
    > File Name: longest_common_prefix.cpp
    > Author: lax
    > Mail: xingkungao@gmail.com
    > Created Time: Sun 07 Dec 2014 04:52:41 PM CST
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
using namespace std;
class Solution {
	public:
		string longestCommonPrefix(vector<string> &strs) {
			string prefix;
			int idx = 0;
			char c;
			if (strs.empty())
				return prefix;

			for (idx = 0; idx < strs[0].length(); idx++)  {
				c = strs[0][idx];
				for (int i = 1; i < strs.size(); i++) {
					if (idx >= strs[i].length() || strs[i][idx] != c)
						return prefix;
				}
				prefix.push_back(c);
			}
			return prefix;
		}
};

int main() {
}

