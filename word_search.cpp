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
				Position() {};
				Position(int a, int b) : x(a), y(b), d(0){}
				Position(int a, int b, int c) : x(a), y(b), d(c){}
			};
			int adj[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1}};
			int m = board.size();
			int len = word.length();
			if (!m || !len)
				return false;
			int n = board[0].size();
			bool flag[m*n];
			memset(flag, 0, sizeof(flag));

			int i, j, k, l;
			int x, y, p;
			Position  cell;
			stack<Position> s;
			for (i = 0; i < m; i++) 
				for (j = 0; j < n; j++) {

					k = 0;
					if (board[i][j] == word[k++]) {
						p = -1;
						flag[i*n+j] = true;
						s.push(Position(i, j, 0));

						while (!s.empty()) {
							if (k == len)
								return true;
							cell = s.top();
							for (l = p + 1; l < 4; l++)  {
								x = cell.x + adj[l][0];
								y = cell.y + adj[l][1];
								if (isValid(x, y, m, n) && !flag[x*n+y] && board[x][y] == word[k]) {
									k++;
									flag[x*n+y] = true;
									s.push(Position(x, y, l));
									p = -1;
									break;
								}
							}
							if (l == 4) {
								flag[(cell.x*n)+cell.y] = false;
								s.pop();
								p = cell.d; 
								k--;
							}
						}
					}
				}
			return false;
		}
		bool isValid(int x, int y, int m, int n) {
			return x >= 0 && x < m && y >= 0 && y < n;
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
			cout << "print board:\n";
			print2DVector(v);
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
