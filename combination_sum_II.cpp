/*************************************************************************
    > File Name: combination_sum_II.cpp
    > Author: lax
    > Mail: xingkungao@gmail.com
    > Created Time: Thu 25 Dec 2014 11:54:22 PM CST
 ************************************************************************/

#include "CPP.h"
#include "utility.h"
using namespace std;

class Solution {
	public:
		vector<vector<int> > combinationSum2(vector<int> &num,int target) {
			vector<vector<vector<int>>> ret(target + 1, vector<vector<int>>());
			ret[0].push_back(vector<int>());
			sort(num.begin(), num.end());
			for (auto item : num) 
				for (int j = target; j >= item; j--) {
					// not use this item
					// no change

					// use this item
					auto v = ret[j - item];
					for (auto& e : v) 
						e.push_back(item);
					ret[j].insert(ret[j].end(), v.begin(), v.end());
				}
			vector<vector<int> > res;
			set<vector<int> > s;
			for (int i = 0; i < ret[target].size(); i++)
				s.insert(ret[target][i]);
			copy(s.begin(), s.end(), back_inserter(res));
			return res;
		}
		void test() {
			vector<int> v;
			int x, t;
			while (1) {
				while (cin >> x && x >= 0)
					v.push_back(x);
				cin >> t;
				print2DVector(combinationSum2(v, t));
				v.clear();
			}
		}
};

int main() {
	Solution s;
	s.test();
}

