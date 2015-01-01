/*************************************************************************
  > File Name: substring_with_concatenation_of_all_words.cpp
  > Author: lax
  > Mail: xingkungao@gmail.com
  > Created Time: Tue 30 Dec 2014 11:08:21 AM CST
 ************************************************************************/

#include "CPP.h"
#include "utility.h"
using namespace std;
struct TrieNode {
	TrieNode *fail;
	TrieNode *next[26];
	int count;
	TrieNode() : fail(0), count(0) {
		memset(next, 0, sizeof(next));
	}
};
class ACAutomata {
	private:
		TrieNode *root;
	public:
		ACAutomata() {
			if (!root) 
				root = new TrieNode();
		}
		~ACAutomata() {
			deleteTrie(root);
		}
		void deleteTrie(TrieNode *root) {
			if (!root)
				return;
			for (int i = 0; i < 26; i++) 
				if (root->next[i])
					deleteTrie(root->next[i]);
			delete root;
		}
		void insert(const char* str, TrieNode *root) {
			int i = 0, idx;
			while (str[i]) {
				idx = str[i] - 'a';
				if (root->next[idx] == NULL) 
					root->next[idx] = new TrieNode();
				root = root->next[idx];
				i++;
			}
			root->count ++;
		}
		void buildACAutomata(TrieNode *root) {
			if (root == NULL)
				return;
			root->fail = 0;
			queue<TrieNode*> q;
			TrieNode *node, *p;
			q.push(root);
			while (!q.empty()) {
				node = q.front();
				q.pop();
				for (int i = 0; i < 26; i++) {
					if (node->next[i]) {
						if (node == root)
							node->next[i]->fail = root;
						else {
							p = node->fail;
							while (p) {
								if (p->next[i]) {
									node->next[i]->fail = p->next[i];
									break;
								}
								p = p->fail;
							}
							if (p == NULL)
								node->next[i]->fail = root;
						}
						q.push(node->next[i]);
					}
				}
			}
		}
};

class Solution {
	public:
		vector<int> findSubstring(string S, vector<string> &L) {
//			return findSubstring1(S, L);
			return findSubstring2(S, L);
		}
		vector<int> findSubstring1(string S, vector<string> &L) {
			vector<int> ret;
			int n = S.length(), m = L.size();
			if (n == 0 || m == 0)
				return ret;
			int len = L[0].length();
			if (n < m * len)
				return ret;
			unordered_map<string, int> dict;
			for (int i = 0; i < m; i++) {
				dict[L[i]] += 1;
			}
			unordered_map<string, int> tmp(dict);
			int i,j;
			unordered_map<string,int>::iterator it;
			for (i = 0; i <= n - m * len; i++) {
				for (j = i; j < i + m * len; j += len) {
					it = tmp.find(S.substr(j, len));
					if (it == tmp.end()) 
						break;
					else if (it->second > 1)
						it->second--;
					else if (it->second == 1) {
						tmp.erase(it);
					}
				}
				if (tmp.empty()) {
					ret.push_back(j - m * len);
				}
				if (j != i)
					tmp = dict;
			}
			return ret;
		}
		vector<int> findSubstring2(string S, vector<string> &L) {
			vector<int> ret;
			int n = S.length(), m = L.size();
			if (n == 0 || m == 0)
				return ret;
			int len = L[0].length();
			if (n < m * len)
				return ret;
			unordered_map<string, int> dict;
			for (int i = 0; i < m; i++) {
				dict[L[i]] += 1;
			}
			for (int i = 0; i <= n - m * len; i++) {
				if (isValid(dict, S, i, i + m * len, len))
					ret.push_back(i);
			}
			return ret;
		}
		bool isValid(unordered_map<string, int> &dict, string &s, int start, int end, int len) {
			if (start == end) 
				return true;
			unordered_map<string,int>::iterator it;
			bool ret;
			for (int i = start; i < end; i += len) {
				it = dict.find(s.substr(i, len));
				if (it == dict.end() || it->second < 1) 
					return false;
				else {
					it->second--;
					ret = isValid(dict, s, i + len, end, len);
					it->second++;
					return ret;
				}
			}
		}
		void test() {
			string s = "barfoothefoobarman";
			vector<string> l(2, string());
			l[0] = "foo";
			l[1] = "bar";
			print1DVector(findSubstring(s, l));

		}
};

int main() {
	Solution s;
	s.test();
}
