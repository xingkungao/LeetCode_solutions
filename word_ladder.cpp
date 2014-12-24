/*************************************************************************
  > File Name: word_ladder.cpp
  > Author: lax
  > Mail: xingkungao@gmail.com
  > Created Time: Wed 24 Dec 2014 08:16:27 PM CST
 ************************************************************************/

#include "CPP.h"
#include "utility.h"
using namespace std;

class Solution {
	public:
		int ladderLength(string start, string end, unordered_set<string> &dict) {
			queue<string> q1;
			queue<string> q2;
			queue<string> *used, *unused;
			int cnt = 0;


			unordered_set<string> can;
			for (auto it = dict.begin(); it != dict.end(); ++it)
				if (match(end, *it))
					can.insert(*it);

			unordered_map<string, bool> map;
			for (auto it = dict.begin(); it != dict.end(); ++it)
				map[*it] = false;


			q1.push(start);
			string node;
			while (!q1.empty() || !q2.empty()) {
				if (!q1.empty()) {
					used = &q1;
					unused = &q2;
				}
				else {
					used = &q2;
					unused = &q1;
				}
				while (!used->empty()) {
					node = used->front();
					if (can.find(node) != can.end())
						return cnt + 2;
					used->pop();
					/*
					   for (auto it = dict.begin(); it != dict.end(); ++it) {
					   if (!map[*it] && match(*it, node)) {
					   unused->push(*it);
					   map[*it] = true;
					   }
					   }
					   */
						for (int i = 0; i < node.length(); i++) {
							char back = node[i];
							for (int j = 0; j < 26; j++) {
								node[i] = 'a' + j;
								auto it = dict.find(node);
								if (it != dict.end() && !map[*it]) {
									unused->push(*it);
									map[*it] = true;
								}
							}
							node[i] = back;
						}
				}
				cnt++;
			}

			return 0;
		}
		bool match(string a, string b) {
			int cnt = 0;
			for (int i = 0; i < a.length(); i++) {
				if (a[i] != b[i]) 
					cnt ++;
				if (cnt == 2)
					return false;
			}
			return cnt == 1;
		}
		void test() {
			string start = "hit";
			string end = "cog";
			unordered_set<string> s;
			s.insert("hot");

			//s.insert("dot");
			s.insert("dog");
			//s.insert("lot");
			s.insert("log");
			 //  s.insert("hot");
			  // s.insert("cot");
			cout << ladderLength(start, end, s) << endl;
		}
};

int main() {
	Solution s;
	s.test();
}
