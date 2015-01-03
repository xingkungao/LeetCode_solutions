/*************************************************************************
  > File Name: simply_path.cpp
  > Author: lax
  > Mail: xingkungao@gmail.com
  > Created Time: Sat 03 Jan 2015 05:24:16 PM CST
 ************************************************************************/

#include "CPP.h"
#include "utility.h"
using namespace std;

class Solution {
	public:
		string simplifyPath(string path) {
			deque<string> stk;
			string ret;
			int i = 0;
			stk.push_back("/");
			while (i < path.length()) {
				if (path[i] == '/') {
					do { 
						i++;
					}
					while (i > 0 && i < path.length() && path[i] == path[i-1]);
				}
				else {
					string token;
					do {
						token.push_back(path[i]);
						i++;
					}
					while (i < path.length() && path[i] != '/'); 
					if (token == ".")
						continue;
					else if (token == "..") {
						if (!stk.empty() && stk.back() != "/") 
							stk.pop_back();
					}
					else 
						stk.push_back(token);
				}

			}
			stk.pop_front();
			ret.push_back('/');
			while (!stk.empty()) {
				ret += stk.front();
				stk.pop_front();
				ret.push_back('/');
			}
			if (ret.length() > 1) ret.pop_back();
			return ret;
		}
		void test() {
			string s;
			while (1) {
				cin >> s;
				cout << simplifyPath(s) << endl;
			}
		}
};

int main() {
	Solution s;
	s.test();
}
