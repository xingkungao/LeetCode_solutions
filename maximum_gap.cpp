/*************************************************************************
  > File Name: maximum_gap.cpp
  > Author: lax
  > Mail: xingkungao@gmail.com
  > Created Time: Wed 07 Jan 2015 09:01:44 PM CST
 ************************************************************************/

#include "CPP.h"
#include "utility.h"
using namespace std;

class Solution {
	public:
		/* the idea(bucket sort): the average gap between all the elements is ceil((max_ele - min_ele + 1) / (n - 1)), 
		 * for the remaining (n-2) elements rather than min_len and max_len, they can't fill in the remaining (n-2) 
		 * buckets by pigeonhole principle. therefore at least one bucket is empty. Notice here we didn't take min_ele
		 * and max_ele into consideration, i.e. min_ele and max_ele are not sotered in any bucket at all. therefore,
		 * for those (n-2) emements, maximumGap is at least as large as the gap length, so there is no need to consider
		 * the inner-bucket distance.
		 * Notice max_ele and min_ele is considered alone
		 **/
		int maximumGap(vector<int> &num) {
			int len = num.size();
			int ret = INT_MIN;
			if (len < 2)
				return 0;
			int bucket[(len-1) * 2];
			memset(bucket, -1, sizeof(bucket));
			int mi = INT_MAX, ma = -1;
			for (int i = 0; i < len; i++) {
				if (mi > num[i])
					mi = num[i];
				if (ma < num[i])
					ma = num[i];
			}

			if (ma == mi)
				return 0;
			int gap = (ma - mi + 1) / (len-1);
			int idx;
			if ((ma-mi+1)%(len-1))
				gap += 1;
			for (int i = 0; i < len; i++) {
				if (num[i] == mi || num[i] == ma)
					continue;
				idx = (num[i] - mi) / gap * 2;
				if (bucket[idx] == -1 || num[i] < bucket[idx])
					bucket[idx] = num[i];
				if (bucket[idx] == -1 || num[i] > bucket[idx+1])
					bucket[idx+1] = num[i];
			}

			idx = 0;
			int pre = mi;

			/* max_ele and min_ele is considered alone
			 * */
			while (idx < 2 * len - 2) {
				while (idx < 2*len - 2 && bucket[idx] == -1)
					idx++;

				if (idx < 2 * len - 2) {
					ret = max(ret, bucket[idx] - pre);
					pre = bucket[idx];
					idx++;
				}
			}
			ret = max(ret, ma - pre);
			return ret;
		}

		void test() {
			vector<int> v;
			int x;
			while (1) {
				while (cin >> x && x != -1000)
					v.push_back(x);
				cout << maximumGap(v) << endl;
				v.clear();
			}
		}
};

int main() {
	Solution s;
	s.test();
}
