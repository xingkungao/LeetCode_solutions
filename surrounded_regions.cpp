/*************************************************************************
  > File Name: surrounded_regions.cpp
  > Author: lax
  > Mail: xingkungao@gmail.com
  > Created Time: Thu 25 Dec 2014 03:19:56 PM CST
 ************************************************************************/

#include "CPP.h"
#include "utility.h"
using namespace std;
class UnionFind {
	private:
		int *parent;
		int *rank;
		int cnt;
	public:
		UnionFind(int n) {
			parent = new int[n];
			rank = new int[n];
			makeset(parent, rank, n);
			cnt = n;
		}
		~UnionFind() {
			delete parent;
			delete rank;
		}

		void makeset(int *array, int *rank, int n) {
			for (int i = 0; i < n; i++) {
				parent[i] = i;
				rank[i]  = 1;
			}
		}

		int find(int node) {
			if (node != parent[node])
				parent[node] = find(parent[node]);
			return parent[node];
		}

		void wunion(int a, int b) {
			int p1 = find(a);
			int p2 = find(b);
			if (p1 == p2)
				return;

			if (rank[p1] < rank[p2]) {
				parent[p1] = p2;
			}
			else {
				parent[p2] = p1;
				if (rank[p1] == rank[p2])
					rank[p1] ++;
			}
			cnt--;
		}
		bool connected(int a, int b) {
			return find(a) == find(b);
		}
};
class Solution {
	public:
		void solve(vector<vector<char> > &board) {
			int direction[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
			int h = board.size();
			if (!h)
				return;
			int w = board[0].size();
			if (!w)
				return;

			UnionFind uf(h * w + 1);
			for (int i = 0; i < h; i++) 
				for (int j = 0; j < w; j++) 
					if (board[i][j] == 'O') {
						if (!i || i == h -1 || !j || j == w-1) {
							uf.wunion(i * w + j, w * h);
						}
						else {
							for (int k = 0; k < 4; k++) {
								if ('O' == board[ i+direction[k][0] ][ j+direction[k][1] ]) {
									uf.wunion(i*w+j, (i+direction[k][0]) * w + j + direction[k][1]);
								}
							}
						}
					}
			for (int i = 0; i < h; i++) 
				for (int j = 0; j < w; j++) {
					if (board[i][j] == 'O' && !uf.connected(i*w+j, h*w)) {
						board[i][j] = 'X';
					}
				}
		}
		void test() {
			vector<vector<char> > board(4, vector<char>(4, 'X'));
			board[1][1] = 'O';
			board[1][2] = 'O';
			board[2][2] = 'O';
			board[3][1] = 'O';
			solve(board);
			print2DVector(board);
		}
};

int main() {
	Solution s;
	s.test();
}
