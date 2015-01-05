/*************************************************************************
  > File Name: best_time_to_buy_and_sell_stock_II.cpp
  > Author: lax
  > Mail: xingkungao@gmail.com
  > Created Time: Mon 05 Jan 2015 08:18:46 PM CST
 ************************************************************************/

#include "CPP.h"
#include "utility.h"
using namespace std;

class Solution {
	public:
		int maxProfit(vector<int> &prices) {
			int ret = 0;
			for (int i = 1; i < prices.size(); i++)
				if (prices[i] > prices[i-1])
					ret += prices[i] - prices[i-1];
			return ret;
		}
		void test() {
			int n, x;
			vector<int> v;
			while (1) {
				cin >> n;
				if (n <= 0)
					break;
				for (int i = 0; i < n; i++) {
					cin >> x;
					v.push_back(x);
				}
				cout << maxProfit(v) << endl;
				v.clear();
			}
		}
};

int main() {
	Solution s;
	s.test();
}
