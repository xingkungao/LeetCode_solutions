/*************************************************************************
  > File Name: combination_sum.cpp
  > Author: lax
  > Mail: xingkungao@gmail.com
  > Created Time: Thu 25 Dec 2014 12:56:16 PM CST
 ************************************************************************/

#include "CPP.h"
#include "utility.h"
using namespace std;
class Solution {
	public:
		/*
		vector<vector<int> > combinationSum2(vector<int> &candidates, int target) {
			vector<vector<vector<int> > > ret(target + 1, vector<vector<int> >());
			ret[0].push_back(vector<int>());

			for (int j = 1; j <= target; j++) {
				int cnt = 0;
				for (int i = 0; i < candidates.size(); i++)  {
					int w = candidates[i];
					if (j >= w && ret[j-w].size() > 0) {
						for (int k = ret[j-w].size() - 1; k >= 0; k--) {
							ret[j].push_back(ret[j-w][k]);
							ret[j][cnt].push_back(w);
							cnt++;
						}
					}
				}
			}
			return ret[target];
		}
		*/

		vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
			sort(candidates.begin(), candidates.end());
			vector<vector<vector<int> > > ret(target + 1, vector<vector<int> >());
			ret[0].push_back(vector<int>());
			for (int i = 0; i < candidates.size(); i++)  {
				int w = candidates[i];
				for (int j = w; j <= target; j++) {
					if (ret[j-w].size() > 0) {
						auto v = ret[j-w];
						for (auto& e : v) 
							e.push_back(w);
						ret[j].insert(ret[j].end(), v.begin(), v.end());
					}
				}
			}
			return ret[target];
		}

		void test() {
			vector<int> v;
			int target, x;
			while (1) {
				while (cin >> x && x >= 0)
					v.push_back(x);
				cin >> target;
				print2DVector(combinationSum(v, target));
				v.clear();
			}
		}
};


int main() {
	vector<Solution>();
	Solution s;
	s.test();
}
