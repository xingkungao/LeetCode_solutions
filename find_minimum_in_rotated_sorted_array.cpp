/*************************************************************************
  > File Name: find_minimum_in_rotated_sorted_array.cpp
  > Author: lax
  > Mail: xingkungao@gmail.com
  > Created Time: Tue 02 Dec 2014 07:43:35 PM CST
 ************************************************************************/

#include  "CPP.h"
#include "utility.h"
using namespace std;

class Solution {
	public:
		int findMin(vector<int> &num) {
			return findMinStandard(num); 
		}
		int findMinStandard(vector<int> &num) {
			int l = 0, r = num.size() -1, mid;
			while (l < r) {
				if (num[l] < num[r])
					return num[l];

				mid = (l + r) / 2;

				if (num[mid] >= num[l])
					l = mid + 1;
				else 
					r = mid;
			}
			return num[l];
		}

		int findMin2(vector<int> &num) {
			int mid, l = 0, r = num.size() - 1;
			if (l == r)
				return num[l];
			int lmin = num[l], rmax = num[r];
			if (lmin < rmax)
				return lmin;
			while (l < r) {
				mid = (l + r) / 2;
				if (mid == l)
					return num[r];
				if (num[mid] < lmin)  { // on the right
					if (mid && num[mid] < num[mid-1])
						return num[mid];
					r = mid;
				}
				else if (num[mid] == num[l])
					return num[r]; 
				else  
					l = mid;
			}
			return num[mid];
		}

		void test() {
			vector<int> v;
			int n;
			int d;
			while (1) {
				while (cin >> d && d != -1000)
					v.push_back(d);
				cout << findMin(v) << endl;
				v.clear();
			}
		}
};
int main()  {
	Solution s;
	s.test();
}
