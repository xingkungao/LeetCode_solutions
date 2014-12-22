/*************************************************************************
  > File Name: 3sum_closest.cpp
  > Author: lax
  > Mail: xingkungao@gmail.com
  > Created Time: Mon 08 Dec 2014 04:28:35 PM CST
 ************************************************************************/

#include "CPP.h"
using namespace std;
class Solution {
	public:
		int threeSumClosest(vector<int> &num, int target) {
			int len = num.size();
			if (len < 3)
				return accumulate(num.begin(), num.end(), 0);
			std::sort(num.begin(), num.end());
			int m = num[0] + num[1] + num[2];
			int l, r, sum;
			for (int i = 0; i < len - 2; i++) {
				l = i + 1;
				r = len - 1;
				while (l < r)  {
					sum = num[i] + num[l] + num[r];
					if (sum == target) 
						return target;
					else {
						if (abs(target - sum) < abs(target - m))
							m = sum;
						sum > target ? r-- : l++;
					}
				}
			}
			return m;

		}
		void test() {
			int a[] = {-1, 2, 1, -4};
			vector<int> v(a, a + 4);
			cout << threeSumClosest(v, 1) << endl;
		
		}

};

int main() {
	Solution s;
	s.test();
}

