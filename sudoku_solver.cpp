/*************************************************************************
  > File Name: sudoku_solver.cpp
  > Author: lax
  > Mail: xingkungao@gmail.com
  > Created Time: Sun 28 Dec 2014 01:41:50 PM CST
 ************************************************************************/

#include "CPP.h"
#include "utility.h"
using namespace std;

class Solution {
	public:
		void solveSudoku(vector<vector<char> > &board) {
			bool row[9][9], col[9][9], sub[3][3][9];
			int d;
			memset(row, 0, sizeof(row));
			memset(col, 0, sizeof(col));
			memset(sub, 0, sizeof(sub));
			pre(row, col, sub, board);
			solveSudokuBacktracking(row, col, sub, board, 0 , 0); 
		}
		bool pre(bool row[][9], bool col[][9], bool sub[][3][9], vector<vector<char> > &board) {
			int d;
			for (int i = 0; i < 9; i++)  {
				for (int j = 0; j < 9; j++) {
					d = board[i][j] - '0';
					if (d >= 1 && d <= 9) {
						d--;
						row[i][d] = true;
						col[d][j] = true;
						sub[i/3][j/3][d] = true;
					}
				}
			}
		}

		bool solveSudokuBacktracking(bool row[][9], bool col[][9], bool sub[][3][9], vector<vector<char> > &board, int r, int c) {
			bool j, k, l;
			if(r == 9)
				return true;
			if (board[r][c] == '.') { 
				for (int i = 0; i < 9; i++) {
					if(!row[r][i] && !col[i][c] && !sub[r/3][c/3][i]) {
						row[r][i] = col[i][c] = sub[r/3][c/3][i] = true;
						board[r][c] = '0' + i + 1;
						if (solveSudokuBacktracking(row, col, sub, board, r + (c + 1) / 9 , (c + 1) % 9)) 
							return true;
						row[r][i] = col[i][c] = sub[r/3][c/3][i] = false;
						board[r][c] = '.';
					}
				}
				return false;
			}
			return solveSudokuBacktracking(row, col, sub, board, r + (c + 1) / 9 , (c + 1) % 9); 
			/*
			else {
				int i = board[r][c] - '0' - 1;
				if (row[r][i] || col[i][c] || sub[r/3][c/3][i])
					return false;
				row[r][i] = col[i][c] = sub[r/3][c/3][i] = true;
				if (solveSudokuBacktracking(row, col, sub, board, r + (c + 1) / 9 , (c + 1) % 9)) 
					return true;
				return false;
			}
			*/
		}
		bool isValidSudoku(vector<vector<char> > &board) {
			bool row[9][9], col[9][9], sub[3][3][9];
			int d;
			memset(row, 0, sizeof(row));
			memset(col, 0, sizeof(col));
			memset(sub, 0, sizeof(sub));
			for (int i = 0; i < 9; i++)  {
				for (int j = 0; j < 9; j++) {
					d = board[i][j] - '0';
					if (d >= 0 && d <= 9) {
						d--;
						if (row[i][d]){
							cout << "row " << i << j << d + 1 << endl;
							return false;
						}
						row[i][d] = true;
						if (col[d][j]){
							cout << "col" << i << j << d + 1 << endl;
							return false;
						}
						col[d][j] = true;
						if (sub[i/3][j/3][d]) {
							cout << "sub" << i << j << d + 1 << endl;
							return false;
						}
						sub[i/3][j/3][d] = true;
					}
				}
			}
			return true;
		}
		void test() {
			vector<vector<char> > board;
			const char* cboard[9] = {"53..7....","6..195...",".98....6.","8...6...3","4..8.3..1","7...2...6",".6....28.","...419..5","....8..79"};

			for (int i = 0; i < 9; i++) 
				board.push_back(vector<char>(cboard[i], cboard[i] + 9));
			print2DVector(board);
			solveSudoku(board);
			print2DVector(board);
			cout << boolalpha << isValidSudoku(board) << endl;
		}

};



int main() {
	Solution s;
	s.test();
}
