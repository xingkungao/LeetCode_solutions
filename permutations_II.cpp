/*************************************************************************
    > File Name: permutations_II.cpp
    > Author: lax
    > Mail: xingkungao@gmail.com
    > Created Time: Tue 16 Dec 2014 07:14:15 PM CST
 ************************************************************************/

#include "CPP.h"
#include "utility.h"
using namespace std;
class Solution {
	public:
		vector<vector<int> > permuteUnique(vector<int> &num) {
			vector<vector<int> > ret;
			int len = num.size();
			if (len <= 0)
				return ret;
			sort(num.begin(), num.end());
			do {
				ret.push_back(num);
			}while (nextPermute(num));
			return ret;
		}
		bool nextPermute(vector<int> &v) {
			int len = v.size();
			int i, j, k;
			i = len - 1;
			while (i) {
				if (v[i] <= v[i-1])
					i--;
				else 
					break;
			}

			if (!i) 
				return false;
			i--;
			
			for (j = len - 1; j >= 0; j--) {
				if (v[j] > v[i]) {
					break;
				}
			}
			swap(v[i], v[j]);
			reverse(v.begin() + i + 1, v.end());
			return true;
		}
		void test() {
			int n, x;
			vector<int> v;
			while (1) {
				cin >> n;
				for (int i = 0; i < n; i++) {
					cin >> x;
					v.push_back(x);
				}
				print2DVector(permuteUnique(v));
				v.clear();
			}
		}
};


int main() {
	Solution s;
	s.test();
}
