/*************************************************************************
  > File Name: find_minimum_in_rotated_sorted_array_II.cpp
  > Author: lax
  > Mail: xingkungao@gmail.com
  > Created Time: Sun 04 Jan 2015 05:08:16 PM CST
 ************************************************************************/

#include "CPP.h"
#include "utility.h"
using namespace std;
class Solution {
	public:
		int findMin(vector<int> &num) {
			int l = 0, r = num.size() - 1, mid;
			while (l < r) {
				if (num[l] < num[r])
					return num[l];

				mid = (l + r) / 2;
				if (num[mid] > num[l])
					l = mid + 1;
				else if (num[mid] == num[l])
					l++;
				else 
					r = mid;
			}
			return num[l];
		}
		void test() {
			vector<int> v;
			int d;
			while (1) {
				while (cin >> d && d != -1000)
					v.push_back(d);
				cout << findMin(v) << endl;
				v.clear();
			}
		}
};

int main() {
	Solution s;
	s.test();
}
