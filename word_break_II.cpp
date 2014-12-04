/************************************************************************* > File Name: word_break_II.cpp
  > Author: lax
  > Mail: xingkungao@gmail.com
  > Created Time: Wed 03 Dec 2014 02:32:04 PM CST
 ************************************************************************/

#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
//#include <unordered_set>
using namespace std;
/*
class Solution {
	public:
		vector<string> wordBreak(string s, unordered_set<string> &dict) {
			struct MyWord{
				int begin;
				int end;
				MyWord(int begin = 0, int end = 0):begin(begin), end(end){}
			};
			vector<vector<vector<MyWord> > > v;
			int len = s.length();
			string word;
			bool f[len];
			for (int i = 0; i < len; i++)
				f[i] = 0;
			for (int i = 0; i < len; i++)  {
				vector< vector<MyWord> > current;
				v.push_back(current);
				for (int j = i; j >= 0; j--) {
					word = s.substr(j, i - j + 1);
					if (dict.find(word) != dict.end())  {
							MyWord m(j, i);
						if (!j) {
							vector<MyWord> ab;
							ab.push_back(m);
							v[i].push_back(ab);
							f[i] = true;
						}
						else if (f[j-1]) {
							f[i] = true;
							for (vector<vector<MyWord>>::iterator it = v[j-1].begin(); it != v[j-1].end(); ++it) {
								vector<MyWord> bb = *it;
								bb.push_back(m);
								v[i].push_back(bb);
							}
							
						}
					}
				}
			}
			vector<string> result;
			for (int i = 0; i < v[len-1].size(); i++) {
				string aaa;
				for (int j = 0; j < v[len-1][i].size(); j++) {
					aaa = aaa + s.substr(v[len-1][i][j].begin, v[len-1][i][j].end - v[len-1][i][j].begin + 1) + " ";
				}
				result.push_back(aaa.substr(0, aaa.size() - 1));
			}
			return result;
		}
		void print(vector<string>& v) {
			for (vector<string>::iterator it = v.begin(); it != v.end(); ++it) {
				cout << "<<" << *it << ">>" <<  endl;
			}
				cout << endl;
		}
};
*/
int main() {
	/*
	Solution s;
	//string str = "leetcode";
	//string str = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
	string str = "aaaaaaaaaaaaaaa";
	unordered_set<string> set = {"a", "aa", "aaa", "aaaa", "aaaaa", "aaaaaa", "aaaaaaa"};
	vector<string> v = s.wordBreak(str, set);
	s.print(v);
	cout << endl;
	*/
}
