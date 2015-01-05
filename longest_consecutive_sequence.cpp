/*************************************************************************
  > File Name: longest_consecutive_sequence.cpp
  > Author: lax
  > Mail: xingkungao@gmail.com
  > Created Time: Tue 23 Dec 2014 04:17:56 PM CST
 ************************************************************************/

#include "CPP.h"
#include "utility.h"
using namespace std;

class Solution {
	public:
		int longestConsecutive(vector<int> &num) {
			int ret = 1;
			int len = num.size();
			int n, d;
			unordered_map<int, int> dict;
			for (int i = 0; i < len; i++) {
				int d = num[i];
				if (dict.find(d) == dict.end()) {
					dict[d] = 1;
					if (dict.find(d-1) != dict.end()) {
						n = dict[d-1] + dict[d];
						dict[d] = dict[d -1 - dict[d-1] + 1] = n;  
						ret = max(ret, n);
					}
					if (dict.find(d+1) != dict.end()) {
						n = dict[d+1] + dict[d];
						dict[d + 1 + dict[d+1] - 1] = n;  
						if (dict[d] == 1)
							dict[d] = n;  
						else 
							dict[d - dict[d] + 1] = n;
						ret = max(ret, n);
					}
				}
			}
			return ret;
		}
		void test() {
			vector<int> v;
			int x;
			while (1) {
				while (cin >> x && x > 0) 
					v.push_back(x);
				cout << longestConsecutive(v) << endl;
				v.clear();
			}
		}
};

int main() {
	Solution s;
	s.test();
}
