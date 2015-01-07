/*************************************************************************
    > File Name: find_peak_element.cpp
    > Author: lax
    > Mail: xingkungao@gmail.com
    > Created Time: Fri 26 Dec 2014 01:09:51 AM CST
 ************************************************************************/

#include "CPP.h"
#include "utility.h"
using namespace std;

class Solution {
	public:
		/** the idea:  just need to find a local maximum
		 */
		int findPeakElement(const vector<int> &num) {
			int l = 0, r = num.size() - 1;
			int mid;
			while (l < r)  {
				mid = l + (r - l) / 2;
				if (num[mid] < num[mid+1])
					l = mid + 1;
				else 
					r = mid;
			}
			return l;
		}

		void test() {
			vector<int> v;
			int x;
			while (1) {
				while (cin >> x && x != -1000)
					v.push_back(x);
				cout << findPeakElement(v) << endl;
				v.clear();
			}
		}
};

int main() {
	Solution s;
	s.test();
}
