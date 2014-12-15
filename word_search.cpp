/*************************************************************************
  > File Name: word_search.cpp
  > Author: lax
  > Mail: xingkungao@gmail.com
  > Created Time: Mon 15 Dec 2014 09:40:12 PM CST
 ************************************************************************/

#include "CPP.h"
#include "utility.h"
using namespace std;

class Solution {
	public:
		bool exist(vector<vector<char> > &board, string word) {
			struct Position {
				int x, y, d;
				Position(int a, int b) : x(a), y(b), d(0){}
				Position(int a, int b, int c) : x(a), y(b), d(d){}
			};
			int dir[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1}};
			int n = board.size();
			int len = word.length();
			bool sign;
			if (!n || !len)
				return false;
			vector<bool> flag(n * n, false);
			int i, j, k = 0;
			int x, y, m;
			for (i = 0; i < n; i++) 
				for (j = 0; j < n; j++) {
					k = 0;
					if (board[i][j] == word[k++]) {
						stack<Position*> s;
						m = -1;
						flag[i*n+j] = true;
						s.push(new Position(i, j, 0));
						while (!s.empty()) {
						if (k == len)
							return true;
							Position *cell = s.top();
							x = cell->x;
							y = cell->y;
							sign = false;
							for (int l = m + 1; l < 4; l++)  {
								x = cell->x + dir[l][0];
								y = cell->y + dir[l][1];
								if (isValid(x, y, n) && !flag[x*n+y] && board[x][y] == word[k++]) {
									cout << "i:" << x << " j:" << y << " char:" << board[x][y] << " flag:" << flag[x*n+y] << endl;
									sign = true;
									flag[x*n+y] = true;
									s.push(new Position(x, y, l));
									m = -1;
									break;
								}
							}
							if (!sign) {
//								flag[x*n+y] = false;
								s.pop();
								m = cell->d; 
								k--;
							}
						}
					}
				}
			return false;
		}
		bool isValid(int x, int y, int n) {
			return x >= 0 && x < n && y >= 0 && y < n;
		}
		void test() {
			string word;
			vector<vector<char> >v;
			vector<char> l0;
			l0.push_back('a');
			l0.push_back('b');
			l0.push_back('c');
			l0.push_back('e');
			vector<char> l1;
			l1.push_back('s');
			l1.push_back('f');
			l1.push_back('c');
			l1.push_back('s');
			vector<char> l2;
			l2.push_back('a');
			l2.push_back('d');
			l2.push_back('e');
			l2.push_back('e');
			v.push_back(l0);
			v.push_back(l1);
			v.push_back(l2);
			while (1) {
				cin >> word; 
				cout << boolalpha << exist(v, word) << endl;
			}


		}
};

int main() {
	Solution s;
	s.test();
}
