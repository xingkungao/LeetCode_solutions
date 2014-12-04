/*************************************************************************
  > File Name: ReverseWordsInAString.cpp
  > Author: lax
  > Mail: xingkungao@gmail.com
  > Created Time: Sun 30 Nov 2014 03:52:57 PM CST
 ************************************************************************/

#include <sstream>
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
/*
class Solution {
	public:
		void reverseWords(string &s) {
			vector<string> v;
			reverseString(s);
			int l, r;
			l = -1;
			r = -2;
			s.append(" ");
			for (int i = 0; i < s.length(); i++) {
				if (s[i] != ' ') {
					r = i;
				}
				else {
					if (r >= l) {
						v.push_back(s.substr(l + 1, r - l));
					}
					l = i;
				}
			}

			s.clear();
			for (int i = 0; i + 1 < v.size(); i++)  {
				reverseString(v[i]);
				s = s + v[i] + ' ';
			}
			if (v.size() >= 1) {
				reverseString(v[v.size() - 1]);
				s += (v[v.size() - 1]);
			}
		}

		void reverseString(string &s) {
			int n = s.length();
			for (int i = 0; i < n / 2; i++) 
				std::swap(s[i],s[n - 1 - i]);
		}
};
*/
class Solution {
	public:
		void reverseWords(string &s) {
			string token;
			string result;
			reverseString(s);
			istringstream iss(s);
			while (iss >> token){
				result.append(reverseString(token) + " ");
			}
			s = string(result, 0, result.length() - 1);
		}

		string& reverseString(string &s) {
			std::reverse(s.begin(), s.end());
			return s;
		}
};
int main() {
	Solution s;
	string a = string("I love    beauty girls");
	s.reverseWords(a);
	cout << "<<" << a << ">>"<<  endl;
}
