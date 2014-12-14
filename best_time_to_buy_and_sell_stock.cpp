/*************************************************************************
    > File Name: best_time_to_buy_and_sell_stock.cpp
    > Author: lax
    > Mail: xingkungao@gmail.com
    > Created Time: Sun 14 Dec 2014 05:40:58 PM CST
 ************************************************************************/

#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;
class Solution {
	public:
		int maxProfit(vector<int> &prices) {
			if (prices.empty())
				return 0;
			int ret = 0, m = prices[0];
			for (int i = 1; i < prices.size(); i++) {
				ret = std::max(ret, prices[i] - m);
				m = std::min(m, prices[i]);
			}
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

