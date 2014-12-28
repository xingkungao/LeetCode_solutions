/*************************************************************************
  > File Name: valid_sudoku.cpp
  > Author: lax
  > Mail: xingkungao@gmail.com
  > Created Time: Sun 28 Dec 2014 01:41:50 PM CST
 ************************************************************************/

#include "CPP.h"
#include "utility.h"
using namespace std;

class Solution {
	public:
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
							cout << "row " << i << j << d+1 << endl;
							return false;
						}
						row[i][d] = true;
						if (col[d][j]){
							cout << "col " << i << j << d+1 << endl;
							return false;
						}
						col[d][j] = true;
						if (sub[i/3][j/3][d]) {
							cout << "sub " << i << j << d +1<< endl;
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
			const char* cboard[9] = {
//				"....5..1.",".4.3.....",".....3..1","8......2.","..2.7....",".15......",".....2...",".2.9.....","..4......"};
//				"129748345","734125678","526139129","217346247","364211594","498578312","641853223","752413866","893275951"};
	//	"534678192","672195348","198342567","859761423","426853971","713924856","961537284","287419635","345286779" };
	"534678912","672195348","198342567","859761423","426853791","713924856","961537284","287419635","345286179" };
				/*
				"53..7....",
				"6..195...",
				".98....6.",
				"8...6...3",
				"4..8.3..1",
				"7...2...6",
				".6....28.",
				"...419..5",
				"....8..79"};
*/
			for (int i = 0; i < 9; i++) 
				board.push_back(vector<char>(cboard[i], cboard[i] + 9));
			print2DVector(board);
			cout << boolalpha << isValidSudoku(board) << endl;

		}
};



		int main() {
			Solution s;
			s.test();
		}
