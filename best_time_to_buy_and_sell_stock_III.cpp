/*************************************************************************
  > File Name: best_time_to_buy_and_sell_stock_III.cpp
  > Author: lax
  > Mail: xingkungao@gmail.com
  > Created Time: Mon 05 Jan 2015 08:42:56 PM CST
 ************************************************************************/

#include "CPP.h"
#include "utility.h"
using namespace std;

class Solution {
	public:
		int maxProfit(vector<int> &prices) {
			return maxProfitDPGeneralize(prices, 2);
		}

		int maxProfitDP(vector<int> &prices) {
			int ret = 0;

			int len = prices.size();
			if (len <= 1)
				return ret;
			int pre[len], next[len];

			pre[0] = 0;
			int m = prices[0];
			for (int i = 1; i < len; i++) {
				pre[i] = max(pre[i-1], prices[i] - m);
				m = min(m, prices[i]);
			}

			next[len-1] = 0;
			m = prices[len-1]; 
			for (int i = len - 2; i >= 0; i--) {
				next[i] = max(next[i+1], m - prices[i]);
				m = max(m, prices[i]);
			}

			ret = 0;
			for (int i = 0; i < len; i++)
				ret = max(ret, pre[i] + next[i]);
			return ret;
		}

		/* idea: f[k][i] represents the max profit within days up to i and transaction up to k
		 * f[k][i] = max(f[k][i-1], maximize(prices[i] - prices[j] + f[k-1][j])) where j < i;
		 * which is equal to f[k][i] = max(f[k-1][i-1], prices[i] + maximize(f[k-1][j] - prices[j])) where j < i;
		 */
		int maxProfitDPGeneralize(vector<int> &prices, int k) {
			int n = prices.size();
			int ret = 0;
			if (n <= 1 || k < 1)
				return ret;

			int maxProfit[k+1][n];

			for (int i = 0; i < n; i++)
				maxProfit[0][i] = 0;

			int tmpMax;
			for (int i = 1; i <= k; i++) {
				tmpMax = maxProfit[i-1][0] - prices[0];
				maxProfit[i][0] = 0;
				for (int j = 1; j < n; j++) {
					maxProfit[i][j] = max(maxProfit[i][j-1], prices[j] + tmpMax);
					tmpMax = max(tmpMax, maxProfit[i-1][j] - prices[j]);
				}
			}

			return maxProfit[k][n-1];
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
