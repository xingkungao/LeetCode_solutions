/*************************************************************************
    > File Name: container_with_most_water.cpp
    > Author: lax
    > Mail: xingkungao@gmail.com
    > Created Time: Sat 06 Dec 2014 04:59:27 PM CST
 ************************************************************************/

#include "CPP.h"
#include "utility.h"
using namespace std;

class Solution {
	public:
		int maxArea(vector<int> &height) {
			int l = 0, r = height.size() -1, ret = 0; 
			while (l < r) {
				ret = max(ret, (r - l) * min(height[l], height[r])); 
				if (height[l] < height[r])  {
					l++;
				}
				else if (height[l] > height[r])
					r--;
				else {
					l++;
					r--;
				}
			}
			return ret;
		}
		void test() {
			vector<int> v;
			int x;
			while (cin >> x && x >= 0) {
				v.push_back(x);
			}
			cout << maxArea(v) << endl;
			v.clear();
		}
};

int main() {
	Solution s;
	s.test();
}
