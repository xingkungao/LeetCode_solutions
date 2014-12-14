/*************************************************************************
  > File Name: letter_combinations_of_a_phone_number.cpp
  > Author: lax
  > Mail: xingkungao@gmail.com
  > Created Time: Sat 13 Dec 2014 04:16:16 PM CST
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <cassert>
#include <unordered_map>
using namespace std;
class Solution {
	public:
		vector<string> letterCombinations(string digits) {
			vector<string> ans;
			unordered_map<int, string> m({ {2, "abc"},
					{3,"def"},
					{4,"ghi"},
					{5, "jkl"},
					{6, "mno"},
					{7, "pqrs"},
					{8, "tuv"},
					{9, "wxyz"}});
			if (!digits.empty())
				letterCombinationsRecursive(ans, m, digits.length() - 1, digits); 
			else {
				string s;
				ans.push_back(s);
			}
			return ans;
		}
		void letterCombinationsRecursive(vector<string> &v, unordered_map<int, string> &m, int pos, string digits) {
			string value = m[digits[pos] - '0'];
			if (digits[pos] < '2')
				return;

			int s;
			if (pos >= 1) {
				letterCombinationsRecursive(v, m, pos - 1, digits);
				s = v.size();
			}

			for (int i = 0; i < value.length(); i++) {
				if (!pos) {
					string line(1, value[i]);
					v.push_back(line);
				}
				else {
					for (int j = 0; j < s; j++) {
						if (!i) 
							v[j].append(1,value[i]);
						else {
							string line = v[j];
							line.pop_back();
							line.append(1, value[i]);
							v.push_back(line);
						}

					}
				}
			}
		};
		void print(vector<string> v) {
			for (int i = 0; i < v.size(); i++) 
				cout << v[i] << endl;
		}
		void test() {
			string s;
			while (1) {
				cin >> s;
				print(letterCombinations(s));
			}
		}
};

int main()  {
	Solution s;
	s.test();
}


