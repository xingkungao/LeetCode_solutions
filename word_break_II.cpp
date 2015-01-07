/************************************************************************* 
  > File Name: word_break_II.cpp
  > Author: lax
  > Mail: xingkungao@gmail.com
  > Created Time: Wed 03 Dec 2014 02:32:04 PM CST
 ************************************************************************/

#include "CPP.h"
#include "utility.h"
using namespace std;

class Solution {
	public:
		vector<string> wordBreak(string s, unordered_set<string> &dict) {
			int len = s.length();
			vector<vector<int> > pre;
			vector<string> ret;
			bool f[len];

			for (int i = 0; i < len; i++)
				f[i] = false;
			for (int i = 0; i < len; i++)  {
				pre.push_back(vector<int>());
				for (int j = i; j >= 0; j--) {
					if (dict.find(s.substr(j, i - j + 1)) != dict.end())  {
						if (!j || f[j-1]) {
							f[i] = true;
							pre[i].push_back(j);
						}
					}
				}
			}
			print2DVector(pre);
			deque<pair<int, int> > solu;
			if (f[len-1]) {
				generate(pre, s, ret, len-1, solu);
			}
			return ret;
		}

		void generate(vector<vector<int> > &pre, string &s, vector<string> &ret, int idx, deque<pair<int,int> > &solu) {
			if (idx < 0) {
				string str;
				for (int i = 0; i < solu.size(); i++) {
					str = str + s.substr(solu[i].first, solu[i].second) + " ";
				}
				if(!str.empty()) {
					str.pop_back();
					ret.push_back(str);
				}
				return;
			}
			int p;
			for (int k = 0; k < pre[idx].size(); k++) {
				p = pre[idx][k];
				solu.push_front(make_pair(p, idx - p + 1));
				generate(pre, s, ret, p - 1, solu);
				solu.pop_front();
			}
		}

		void test (){
			/*
			   string str = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"; 
			   unordered_set<string> set = {"a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"};
			   */


			/*
			   string str = "catsanddog";
			   unordered_set<string> set = {"cat", "cats", "and", "sand", "dog"};
			   */
			string str = "a";
			unordered_set<string> set = {"a"};
			vector<string> v = wordBreak(str, set);
			print(v);
			cout << endl;
		}

		void print(vector<string>& v) {
			for (vector<string>::iterator it = v.begin(); it != v.end(); ++it) {
				cout << "<<" << *it << ">>" <<  endl;
			}
			cout << endl;
		}
};
int main() {
	Solution s;
	s.test();
}
