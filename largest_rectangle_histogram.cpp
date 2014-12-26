/*************************************************************************
  > File Name: largest_rectangle_histogram.cpp
  > Author: lax
  > Mail: xingkungao@gmail.com
  > Created Time: Fri 26 Dec 2014 12:24:03 PM CST
 ************************************************************************/

#include "CPP.h"
#include "utility.h"
using namespace std;

class Solution {
	public:
		int largestRectangleArea(vector<int> &height) {
			stack<int> s;
			height.push_back(-1);
			int h;
			int ret = 0;
			for (int i = 0; i < height.size(); i++) {
				while (!s.empty() && height[s.top()] >= height[i]) {
					h = height[s.top()];
					s.pop();
//					cout << "i:" << i << ", height:" <<  h << ", width:" << (s.empty() ? i : i - 1- s.top()) << endl;
					ret = max(ret, h * (s.empty() ? i : i - 1 - s.top()));
				}
				s.push(i);
			}
			height.pop_back();
			return ret;
		}
		void test() {
			vector<int> v;
			int x;
			while (cin >> x && x >= 0) {
				v.push_back(x);
			}
			cout << largestRectangleArea(v) << endl;
			v.clear();

		}
};

int main() {
	Solution s;
	s.test();
}
