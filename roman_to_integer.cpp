/*************************************************************************
    > File Name: roman_to_integer.cpp
    > Author: lax
    > Mail: xingkungao@gmail.com
    > Created Time: Sun 07 Dec 2014 04:20:21 PM CST
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <unordered_map>
#include <stack>
#include <string>
#include <vector>
using namespace std;
class Solution {
	public:
		int romanToInt(string s) {
			int result = 0;
			unordered_map<int, int> map = 
			{{'I', 1},
				{'V', 5},
				{'X', 10},
				{'L', 50},
				{'C', 100},
				{'D', 500},
				{'M',1000}};
			int w, v;
			for (int i = 0; i < s.length() - 1; i++) {
				if (map[s[i]] < map[s[i+1]])
					result += -map[s[i]];
				else 
					result += map[s[i]];
			}
			result += map[s[s.length() -1 ]];
			return result;
		}
		string intToRoman(int num) {
			int i = 0;
			stack<string> s;
			vector<string> v;
			string token;
			char a, b, c;
			int d;
			char digits[] = "IVXLCDM";
			for (int i = 0; i < 7; i++) {
				token = string(1, digits[i]);
				v.push_back(token);
			}
			while(num) {
				token.clear();
				d = num % 10;
				num /= 10;
				if (i == 3) {
					for (int k = 0; k < d; k++)
						s.push(v[6]);
					break;
				}
				if (d == 9)
					s.push(v[2*i] + v[2*i+2]);
				else if (d >= 5) { 
					token += v[2*i+1];
					for (int k = 0; k < d - 5; k++)
						token += v[2*i];
					s.push(token);
				}
				else if (d == 4) {
					s.push(v[2*i] + v[2*i+1]);
				}
				else {
					for (int k = 0; k < d; k++)
						token += v[2*i];
					s.push(token);

				}
				i++;
			}
			string result;
			while (!s.empty()) {
				result += s.top();
				s.pop();
			}
			return result;

		}
		void test() {
			int s;
			cout << romanToInt("MCCXXXIV") << endl;
			while (1) {
				cin >> s;
				cout << boolalpha << (romanToInt(intToRoman(s)) == s) << endl;
			}
		}
};

int main() {
	Solution s;
	s.test();
}

