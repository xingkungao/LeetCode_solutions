/*************************************************************************
    > File Name: plus_one.cpp
    > Author: lax
    > Mail: xingkungao@gmail.com
    > Created Time: Mon 08 Dec 2014 10:15:05 PM CST
 ************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;
class Solution {
	public:
		vector<int> plusOne(vector<int> &digits) {
			int c = 1;
			vector<int> ans;
			int len = digits.size();
			for (int i = len - 1; i >= 0; i--) {
				ans.push_back((digits[i] + c) % 10);
				c = (digits[i] + c) / 10;
			}
			if (c)
				ans.push_back(c);
			reverse(ans.begin(), ans.end());
			return ans;
		}
};

int main() {
	Solution s;
}
