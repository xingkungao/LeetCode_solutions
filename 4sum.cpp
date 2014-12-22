/*************************************************************************
  > File Name: 4sum.cpp
  > Author: lax
  > Mail: xingkungao@gmail.com
  > Created Time: Mon 22 Dec 2014 04:16:55 PM CST
 ************************************************************************/

#include "CPP.h"
#include "utility.h"
using namespace std;

class Solution {
	public:
		vector<vector<int> > fourSum(vector<int> &num, int target) {
			vector<vector<int> > ret;
			int len = num.size();
			sort(num.begin(), num.end());

			for (int i = 0; i < len - 3; i++) {
				if (i && num[i] == num[i-1])
					continue;
				for (int j = i + 1; j < len - 2; j++)  {
					// notice! here when j == i + 1, we should not skip duplictes in case that the duplicates at the beginning of the vector is right candiates
					if (j > i + 1 && num[j] == num[j-1])
						continue;
					int l = j + 1, r = len - 1;
					while (l < r) {
						if (num[i] + num[j] + num[l] + num[r] == target) {
							vector<int> v;
							v.push_back(num[i]);
							v.push_back(num[j]);
							v.push_back(num[l]);
							v.push_back(num[r]);
							ret.push_back(v);
							do {
								l++;
							}while (num[l] == num[l-1]);
							do {
								r--;
							}while (num[r] == num[r+1]);
						}
						else  { 
							(num[i] + num[j] + num[l] + num[r] > target) ? r-- : l++; 
						}
					}
				}
			}
			return ret;
		}
		void test() {
			//int a[] = {1, 0, -1, 0, -2, 2};
			int a[] = {0, 0,0 , 0};
			vector<int> v(a, a + sizeof(a) / sizeof(int));
			print1DVector(v);
			print2DVector(fourSum(v, 0));
		}
};


int main() {
	Solution s;
	s.test();
}


